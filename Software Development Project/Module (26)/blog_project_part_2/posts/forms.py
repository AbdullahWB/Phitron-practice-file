from django import forms
from .models import Post

class PostsFrom(forms.ModelForm):
    class Meta:
        model  = Post
        exclude = ['author']
        #fields = '__all__' # if you want to show all form fields
        # fields = ['name', 'email',] # if you want to show specific fields
        # exclude = ['bio'] # if you want to show all fields without some specific fields
        