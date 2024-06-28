from django import forms


class contactForm(forms.Form):
    name = forms.CharField(label="user_name")
    email = forms.EmailField(label="user_email")
