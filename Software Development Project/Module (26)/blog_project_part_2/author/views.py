from django.shortcuts import render, redirect
from . import forms
from django.contrib.auth.forms import AuthenticationForm, PasswordChangeForm
from django.contrib.auth import authenticate, login, update_session_auth_hash
from django.contrib import messages
from django.contrib.auth.decorators import login_required

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

@login_required
def profile(request):
    if request.method == 'POST':
        form = forms.ChangeUserData(request.POST, instance = request.user)
        if form.is_valid():
            form.save()
            messages.success(request, 'profile account update successfully ')
            return redirect('profile')
    else:
        form = forms.ChangeUserData(instance = request.user)
    return render(request, 'author/profile.html', {'form': form}) 


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
