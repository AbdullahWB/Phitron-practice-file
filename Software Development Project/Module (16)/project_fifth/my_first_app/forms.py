from typing import Any
from django import forms
from django.core import validators


# wed gets == field to html input field
class contactForm(forms.Form):
    name = forms.CharField(
        label="user_name",
        initial="Mohammad Abdullah",
        help_text="input field upto 50 characters",
        widget=forms.Textarea(attrs={"id": "name", "placeholder": "Enter user name"}),
    )  # you can change the id name by widget
    file = forms.FileField(label="file")
    email = forms.EmailField(label="user_email")
    age = forms.IntegerField(label="user_age")
    weights = forms.FloatField(label="user_weights")
    balance = forms.DecimalField(label="user_balance")
    check = forms.BooleanField(label="user_check")
    birth_date = forms.DateField(
        label="User Birth Date", widget=forms.SelectDateWidget(years=range(1900, 2100))
    )
    appointments = forms.ChoiceField(
        label="User Appointments",
        choices=[
            ("1", "Consultation"),
            ("2", "Follow-up"),
            ("3", "Routine Check-up"),
            ("4", "Emergency"),
        ],
        widget=forms.RadioSelect,
    )
    food = forms.MultipleChoiceField(
        label="Favorite Foods",
        choices=[
            ("pizza", "Pizza"),
            ("burger", "Burger"),
            ("pasta", "Pasta"),
            ("salad", "Salad"),
            ("sushi", "Sushi"),
        ],
        widget=forms.CheckboxSelectMultiple,
    )


class StudentData(forms.Form):
    name = forms.CharField(
        label="Student Name",
        widget=forms.TextInput,
        validators=[
            validators.MinLengthValidator(10, message="Enter a name with at least 10 characters")
        ]
    )
    email = forms.EmailField(
        label="Student Email",
        widget=forms.EmailInput,
        validators=[
            validators.EmailValidator(message="Enter a valid email address")
        ]
    )
    password = forms.CharField(
        label="Password",
        widget=forms.PasswordInput,
        validators=[
            validators.MinLengthValidator(8, message="Password must be at least 8 characters long")
        ]
    )

    # def clean(self):
    #     clean_data = super().clean()
    #     valName = self.cleaned_data["name"]
    #     valEmail = self.cleaned_data["email"]
    #     valPassword = self.cleaned_data["password"]

    #     if len(valName) < 10:
    #         raise forms.ValidationError("Enter a name with at least 10 characters")
    #     if not valEmail.endswith('.com'):
    #         raise forms.ValidationError("Enter an email address with '@example.com'")
    #     if len(valPassword) < 8:
    #         raise forms.ValidationError("Password must be at least 8 characters long")

    # def clean_name(self):
    #     valname = self.cleaned_data["name"]
    #     if len(valname) < 10:
    #         raise forms.ValidationError("Enter a name with at least 10 characters")
    #     return valname  # Return the cleaned data

    # def clean_email(self):
    #     valemail = self.cleaned_data["email"]
    #     if not valemail.endswith('@example.com'):
    #         raise forms.ValidationError("Enter an email address with '@example.com'")
    #     return valemail  # Return the cleaned data

    # def clean_password(self):
    #     valpassword = self.cleaned_data["password"]
    #     if len(valpassword) < 8:
    #         raise forms.ValidationError("Password must be at least 8 characters long")
    #     return valpassword  # Return the cleaned data


class PasswordValidationProject(forms.Form):
    name = forms.CharField(widget=forms.TextInput)
    password = forms.CharField(widget=forms.PasswordInput)
    confirm_password = forms.CharField(widget=forms.PasswordInput)
    
    def clean(self):
        cleaned_data = super().clean()
        val_pass  = self.cleaned_data["password"]
        val_con_pass  = self.cleaned_data["confirm_password"]
        val_name = self.cleaned_data["name"]
        if val_pass != val_con_pass:
            raise forms.ValidationError("Passwords do not match")
        if len(val_name) < 10:
            raise forms.ValidationError("name must be at least 10 characters")