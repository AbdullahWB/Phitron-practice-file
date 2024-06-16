from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.

def home(request):
    return render(request ,'navigation/main.html')

def about(request):
    return render(request ,'navigation/about.html')

def contact(request):
    return render(request ,'navigation/contact.html')