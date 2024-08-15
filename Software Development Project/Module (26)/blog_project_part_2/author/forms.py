from django import forms
# from .models import Author
from django.contrib.auth.models import User
from django.contrib.auth.forms import UserCreationForm

# class AuthorFrom(forms.ModelForm):
#     class Meta:
#         model  = Author
#         fields = '__all__' # if you want to show all form fields
        # fields = ['name', 'email',] # if you want to show specific fields
        # exclude = ['bio'] # if you want to show all fields without some specific fields
        
        
class RegistrationForm(UserCreationForm):
    first_name = forms.CharField(widget=forms.TextInput(attrs={'id':'required'}))
    last_name = forms.CharField(widget=forms.TextInput(attrs={'id':'required'}))
    
    class Meta:
        model = User
        fields = ['username', 'first_name', 'last_name', 'email']
        
        