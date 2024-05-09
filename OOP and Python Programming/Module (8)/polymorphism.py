# poly --> many (multiple)
# morph --> shape 

class Animal:
    def __init__(self, name) -> None:
        self.name = name
        
    def make_sounds(self):
        print("animal: make some kind of sounds")

class Cat(Animal):
    def __init__(self, name) -> None:
        super().__init__(name)
    
    def make_sounds(self):
        print("cat: maw maw maw maw maw maw maw maw maw")
    
pussy_cat=Cat('pussy_in_boots')
pussy_cat.make_sounds()