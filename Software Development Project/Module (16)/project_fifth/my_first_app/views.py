from django.shortcuts import render


# Create your views here.
def index(request):
    return render(request, "my_first_app/index.html")


def about(request):
    return render(request, "my_first_app/index.html")