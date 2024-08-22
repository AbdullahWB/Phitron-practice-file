from django.forms import BaseModelForm
from django.http import HttpResponse
from django.shortcuts import render, redirect
from . import forms, models
from posts.models import Post
from django.contrib.auth.decorators import login_required
from django.views.generic import CreateView
from django.urls import reverse_lazy

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


#add post using class based views
class AddPostCreateView(CreateView):
    model = models.Post
    form_class = forms.PostsFrom
    template_name = 'posts/index.html'
    success_url = reverse_lazy('add_posts')
    def form_valid(self, form):
        form.instance.author = self.request.user
        return super().form_valid(form)
        


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