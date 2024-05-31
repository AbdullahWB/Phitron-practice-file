import os
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Input, Conv2D, MaxPooling2D, Flatten, Dense, Dropout, BatchNormalization, LSTM, TimeDistributed
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.callbacks import EarlyStopping, ModelCheckpoint, ReduceLROnPlateau
from tensorflow.keras.regularizers import l2
from sklearn.utils.class_weight import compute_class_weight
import matplotlib.pyplot as plt

# Define image parameters
image_height = 385
image_width = 387
image_channels = 3  # Assuming RGB images

# Define the class names
class_names = ['HandBike', 'Maths', 'Sitting', 'Walking']
num_classes = len(class_names)

# Function to print class distribution
def print_class_distribution(directory, class_names):
    print(f"Class distribution in '{directory}':")
    for class_name in class_names:
        class_path = os.path.join(directory, class_name)
        if os.path.exists(class_path):
            num_images = len([name for name in os.listdir(class_path) if os.path.isfile(os.path.join(class_path, name))])
            print(f"  {class_name}: {num_images} images")
        else:
            print(f"  {class_name}: 0 images")

# Set paths to the directories on Kaggle
base_dir = '/kaggle/input/scalogram-new'  # Change this to your dataset folder name
train_dir = os.path.join(base_dir, 'train')
validation_dir = os.path.join(base_dir, 'validation')
test_dir = os.path.join(base_dir, 'test')

# Check and print class distribution
print("Training data distribution:")
print_class_distribution(train_dir, class_names)
print("Validation data distribution:")
print_class_distribution(validation_dir, class_names)
print("Test data distribution:")
print_class_distribution(test_dir, class_names)

# Compute class weights
train_class_counts = np.array([len(os.listdir(os.path.join(train_dir, class_name))) for class_name in class_names])
class_weights = compute_class_weight(class_weight='balanced', classes=np.arange(num_classes), y=np.concatenate([[i] * count for i, count in enumerate(train_class_counts)]))
class_weights = dict(enumerate(class_weights))

# Convert class weights to list for easy access in the generator
class_weight_list = [class_weights[i] for i in range(num_classes)]

# Custom generator to load smaller batches of files dynamically
def custom_generator(directory, datagen, batch_size, target_size, class_names, class_weights):
    class_indices = {class_name: idx for idx, class_name in enumerate(class_names)}
    while True:
        batch_images = []
        batch_labels = []
        for class_name, weight in zip(class_names, class_weights):
            class_path = os.path.join(directory, class_name)
            file_list = os.listdir(class_path)
            np.random.shuffle(file_list)
            for file in file_list:
                image_path = os.path.join(class_path, file)
                image = tf.keras.preprocessing.image.load_img(image_path, target_size=target_size)
                image = tf.keras.preprocessing.image.img_to_array(image)
                image = datagen.random_transform(image)
                image = datagen.standardize(image)
                batch_images.append(image)
                batch_labels.append(class_indices[class_name])
                if len(batch_images) >= batch_size:
                    batch_images = np.array(batch_images)
                    batch_labels = np.array(batch_labels)
                    batch_labels = tf.keras.utils.to_categorical(batch_labels, num_classes=len(class_names))
                    yield batch_images, batch_labels
                    batch_images, batch_labels = [], []

batch_size = 8
target_size = (image_height, image_width)
time_steps = 10  # Number of frames in each sequence

def sequence_generator(directory, datagen, batch_size, target_size, class_names, class_weights, time_steps):
    class_indices = {class_name: idx for idx, class_name in enumerate(class_names)}
    while True:
        batch_images = []
        batch_labels = []
        for class_name, weight in zip(class_names, class_weights):
            class_path = os.path.join(directory, class_name)
            file_list = os.listdir(class_path)
            np.random.shuffle(file_list)
            for file in file_list:
                image_path = os.path.join(class_path, file)
                image = tf.keras.preprocessing.image.load_img(image_path, target_size=target_size)
                image = tf.keras.preprocessing.image.img_to_array(image)
                image = datagen.random_transform(image)
                image = datagen.standardize(image)
                batch_images.append(image)
                batch_labels.append(class_indices[class_name])
                if len(batch_images) >= batch_size * time_steps:
                    batch_images = np.array(batch_images).reshape(batch_size, time_steps, *target_size, image_channels)
                    batch_labels = np.array(batch_labels[:batch_size * time_steps:time_steps])
                    batch_labels = tf.keras.utils.to_categorical(batch_labels, num_classes=len(class_names))
                    yield batch_images, batch_labels
                    batch_images, batch_labels = [], []

train_generator = sequence_generator(train_dir, train_datagen, batch_size, target_size, class_names, class_weight_list, time_steps)
validation_generator = sequence_generator(validation_dir, test_datagen, batch_size, target_size, class_names, class_weight_list, time_steps)
test_generator = sequence_generator(test_dir, test_datagen, batch_size, target_size, class_names, class_weight_list, time_steps)

# Calculate steps per epoch
train_steps = sum([len(files) for r, d, files in os.walk(train_dir) if not d]) // (batch_size * time_steps)
validation_steps = sum([len(files) for r, d, files in os.walk(validation_dir) if not d]) // (batch_size * time_steps)
test_steps = sum([len(files) for r, d, files in os.walk(test_dir) if not d]) // (batch_size * time_steps)

# Build the model
model = Sequential([
    Input(shape=(time_steps, image_height, image_width, image_channels)),
    TimeDistributed(Conv2D(32, (3, 3), activation='relu', kernel_regularizer=l2(0.001))),
    TimeDistributed(MaxPooling2D(pool_size=(2, 2))),
    TimeDistributed(BatchNormalization()),
    TimeDistributed(Dropout(0.3)),

    TimeDistributed(Conv2D(64, (3, 3), activation='relu', kernel_regularizer=l2(0.001))),
    TimeDistributed(MaxPooling2D(pool_size=(2, 2))),
    TimeDistributed(BatchNormalization()),
    TimeDistributed(Dropout(0.3)),

    TimeDistributed(Conv2D(128, (3, 3), activation='relu', kernel_regularizer=l2(0.001))),
    TimeDistributed(MaxPooling2D(pool_size=(2, 2))),
    TimeDistributed(BatchNormalization()),
    TimeDistributed(Dropout(0.4)),

    TimeDistributed(Conv2D(256, (3, 3), activation='relu', kernel_regularizer=l2(0.001))),
    TimeDistributed(MaxPooling2D(pool_size=(2, 2))),
    TimeDistributed(BatchNormalization()),
    TimeDistributed(Dropout(0.4)),

    TimeDistributed(Conv2D(512, (3, 3), activation='relu', kernel_regularizer=l2(0.001))),
    TimeDistributed(MaxPooling2D(pool_size=(2, 2))),
    TimeDistributed(BatchNormalization()),
    TimeDistributed(Dropout(0.5)),

    TimeDistributed(Flatten()),
    
    LSTM(256, return_sequences=True),
    Dropout(0.5),
    LSTM(128),
    Dropout(0.5),
    
    Dense(num_classes, activation='softmax')
])

# Compile the model
model.compile(optimizer='adam', loss='categorical_crossentropy', metrics=['accuracy'])

# Callbacks
early_stopping = EarlyStopping(monitor='val_loss', patience=10, restore_best_weights=True)
checkpoint = ModelCheckpoint('best_model.keras', monitor='val_accuracy', save_best_only=True, mode='max')
reduce_lr = ReduceLROnPlateau(monitor='val_loss', factor=0.2, patience=5, min_lr=1e-5)

# Train the model
history = model.fit(
    train_generator,
    steps_per_epoch=train_steps,
    validation_data=validation_generator,
    validation_steps=validation_steps,
    epochs=50,
    callbacks=[early_stopping, checkpoint, reduce_lr]
)

# Evaluate the model
test_loss, test_accuracy = model.evaluate(test_generator, steps=test_steps)
print(f"Test Accuracy: {test_accuracy * 100:.2f}%")

# Plot training & validation accuracy and loss values
plt.figure(figsize=(12, 4))
plt.subplot(1, 2, 1)
plt.plot(history.history['accuracy'])
plt.plot(history.history['val_accuracy'])
plt.title('Model accuracy')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.legend(['Train', 'Validation'], loc='upper left')

plt.subplot(1, 2, 2)
plt.plot(history.history['loss'])
plt.plot(history.history['val_loss'])
plt.title('Model loss')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.legend(['Train', 'Validation'], loc='upper left')

plt.show()