from django.shortcuts import render, redirect
from . import forms

# Create your views here.

def add_posts(request):
    if request.method == 'POST':
        posts_form = forms.PostsFrom(request.POST)
        if posts_form.is_valid():
            posts_form.save()
            return redirect('add_posts')
    else:
        posts_form = forms.PostsFrom()
    return render(request, 'posts/index.html', {'form': posts_form})