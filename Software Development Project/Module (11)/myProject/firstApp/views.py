from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def home(request):
    return HttpResponse("this is fist app home page")

def courses(request):
    return HttpResponse("Hello this is my courses page")    