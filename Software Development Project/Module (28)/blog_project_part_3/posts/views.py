from django.forms import BaseModelForm
from django.http import HttpResponse
from django.shortcuts import render, redirect
from . import forms, models
from posts.models import Post
from django.contrib.auth.decorators import login_required
from django.views.generic import CreateView
from django.urls import reverse_lazy
from django.views.generic import UpdateView
from django.views.generic import DeleteView
from django.utils.decorators import method_decorator
from django.views.generic import DetailView

# Create your views here.
""" 
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
    return render(request, 'posts/index.html', {'form': posts_form}) """


#add post using class based views
@method_decorator(login_required, name='dispatch')
class AddPostCreateView(CreateView):
    model = models.Post
    form_class = forms.PostsFrom
    template_name = 'posts/index.html'
    success_url = reverse_lazy('add_posts')
    def form_valid(self, form):
        form.instance.author = self.request.user
        return super().form_valid(form)
        


""" @login_required
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
 """

#* update posts / edit posts
@method_decorator(login_required, name='dispatch')
class EditPostView(UpdateView):
    model = models.Post
    form_class = forms.PostsFrom
    template_name = 'posts/index.html'
    pk_url_kwarg = 'id'
    success_url = reverse_lazy('home')


""" @login_required
def delete_posts(request, id):
    post = models.Post.objects.get(pk=id)
    post.delete()
    return redirect('home') """



#? delete post view
@method_decorator(login_required, name='dispatch')
class DeletePostView(DeleteView):
    model = models.Post
    template_name = 'posts/delete.html'
    success_url = reverse_lazy('home')
    pk_url_kwarg = 'id'


class DetailPostView(DetailView):
    model = models.Post
    pk_url_kwarg = 'id'
    template_name = 'posts/post_details.html'
    
    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        post = self.object 
        comments = post.comments.objects.all()
        if self.request.method == 'POST':
            comment_form = forms.CommentForm(data=self.request.POST)
            if comment_form.is_valid():
                new_comment = comment_form.save(commit=False)
                new_comment.post = post
                new_comment.save()
            else:
                comment_form = forms.CommentForm()
                
            context['comments'] = comments
            context['comment_form'] = comment_form
            return context