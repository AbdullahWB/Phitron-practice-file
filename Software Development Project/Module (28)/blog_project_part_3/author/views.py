from typing import Any
from django.shortcuts import render, redirect
from . import forms
from django.contrib.auth.forms import AuthenticationForm, PasswordChangeForm
from django.contrib.auth import authenticate, login, update_session_auth_hash, logout
from django.contrib import messages
from django.contrib.auth.decorators import login_required
from posts.models import Post
from django.contrib.auth.views import LoginView, LogoutView
from django.urls import reverse_lazy

# Create your views here.

# def add_author(request):
#     if request.method == 'POST':
#         author_form = forms.AuthorFrom(request.POST)
#         if author_form.is_valid():
#             author_form.save()
#             return redirect('add_author')
#     else:
#         author_form = forms.AuthorFrom()
#     return render(request, 'author/index.html', {'form': author_form})

def register(request):
    if request.method == 'POST':
        form = forms.RegistrationForm(request.POST)
        if form.is_valid():
            form.save()
            messages.success(request, 'your account successfully registered')
            return redirect('register')
    else:
        form = forms.RegistrationForm()
    return render(request, 'author/register.html', {'form': form, 'type': 'Registration'})

def user_login(request):
    if request.method == 'POST':
        form = AuthenticationForm(request, request.POST)
        if form.is_valid():
            user_name = form.cleaned_data['username']
            user_pass = form.cleaned_data['password']
            user = authenticate(username=user_name, password=user_pass)
            if user is not None:
                messages.success(request, 'your account successfully log in')
                login(request, user)
                return redirect('profile')
            else:
                messages.warning(request, 'log in information is not available')
                return redirect('register')
    else:
        form = AuthenticationForm()
    return render(request, 'author/register.html', {'form': form, 'type':'Login'}) 


#* login view by class
class UserLoginView(LoginView):
    template_name = 'author/register.html'
    # success_url = reverse_lazy('profile')
    
    def get_success_url(self):
        return reverse_lazy('profile')
    
    def form_valid(self, form):
        messages.success(self.request, 'Logged in successfully')
        return super().form_valid(form)
    
    def form_invalid(self, form):
        messages.warning(self.request, 'Logged in information is not incorrect')
        return super().form_invalid(form)
    
    def get_context_data(self, **kwargs: Any) -> dict[str, Any]:
        context = super().get_context_data(**kwargs)
        context['type'] = 'login'
        return context


@login_required
def profile(request):
    data = Post.objects.filter(author = request.user)
    return render(request, 'author/profile.html' , {'data': data}) 


@login_required
def edit_profile(request):
    if request.method == 'POST':
        form = forms.ChangeUserData(request.POST, instance = request.user)
        if form.is_valid():
            form.save()
            messages.success(request, 'profile account update successfully ')
            return redirect('profile')
    else:
        form = forms.ChangeUserData(instance = request.user)
    return render(request, 'author/update_profile.html', {'form': form}) 


def pass_change(request):
    if request.method == 'POST':
        form = PasswordChangeForm(request.user, data=request.POST)
        if form.is_valid():
            form.save()
            messages.success(request, 'password updated successfully')
            update_session_auth_hash(request, form.user)
            return redirect('profile')
    else:
        form = PasswordChangeForm(user=request.user)
    return render(request, 'author/pass_change.html', {'form': form})


def user_logout(request):
    logout(request)
    return redirect('user_login')
