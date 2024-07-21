from django.shortcuts import render
from . import forms

# Create your views here.

def add_author(request):
    author_form = forms.AuthorFrom()
    return render(request, 'author/index.html', {'form': author_form})