from django.http import *

def contact(request):
    return HttpResponse("Hello this is my contact page")


def home(request):
    return HttpResponse("Hello this is my home page")   