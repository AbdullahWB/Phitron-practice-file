from django import forms
from .models import Album
from django.forms.widgets import DateInput

class AlbumForm(forms.ModelForm):
    class Meta:
        model = Album
        fields = ['album_name', 'musician', 'release_date', 'rating']
        widgets = {
            'release_date': DateInput(attrs={'type': 'date'}),
        }