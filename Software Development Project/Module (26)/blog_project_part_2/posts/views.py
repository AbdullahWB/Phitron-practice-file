from django.shortcuts import render, redirect
from . import forms, models
from posts.models import Post
from django.contrib.auth.decorators import login_required

# Create your views here.

@login_required
def add_posts(request):
    if request.method == 'POST':
        posts_form = forms.PostsFrom(request.POST)
        if posts_form.is_valid():
            # posts_form.cleaned_data['author'] = request.user
            posts_form.instance.author = request.user
            posts_form.save()
            return redirect('add_posts')
    else:
        posts_form = forms.PostsFrom()
    return render(request, 'posts/index.html', {'form': posts_form})


@login_required
def edit_posts(request, id):
    post = models.Post.objects.get(pk=id)
    posts_form = forms.PostsFrom(instance=post)
    print(post.title)
    if request.method == 'POST':
        posts_form = forms.PostsFrom(request.POST, instance=post)
        if posts_form.is_valid():
            posts_form.instance.author = request.user
            posts_form.save()
            return redirect('home')
    return render(request, 'posts/index.html', {'form': posts_form})


@login_required
def delete_posts(request, id):
    post = models.Post.objects.get(pk=id)
    post.delete()
    return redirect('home')