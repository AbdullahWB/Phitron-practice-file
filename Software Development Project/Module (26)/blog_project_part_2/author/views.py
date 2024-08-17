from django.shortcuts import render, redirect
from . import forms
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth import authenticate, login
from django.contrib import messages

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
                return redirect('user_login')
            else:
                messages.warning(request, 'log in information is not available')
                return redirect('register')
    else:
        form = AuthenticationForm()
    return render(request, 'author/register.html', {'form': form, 'type':'Login'}) #12