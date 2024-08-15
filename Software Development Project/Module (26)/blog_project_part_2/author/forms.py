from django import forms
from .models import Author

class AuthorFrom(forms.ModelForm):
    class Meta:
        model  = Author
        fields = '__all__' # if you want to show all form fields
        # fields = ['name', 'email',] # if you want to show specific fields
        # exclude = ['bio'] # if you want to show all fields without some specific fields
        