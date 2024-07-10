from django.shortcuts import render
from .forms import *


# Create your views here.
def index(request):
    return render(request, "./my_first_app/index.html")


def about(request):
    print(request.POST)
    if request.method == "POST":
        email = request.POST.get("email")
        password = request.POST.get("password")
        select = request.POST.get("select")
        return render(
            request,
            "./my_first_app/about.html",
            {"email": email, "password": password, "select": select},
        )
    else:
        return render(request, "./my_first_app/about.html")


def submit_from(request):
    return render(request, "./my_first_app/form.html")


def DjangoFrom(request):
    if request.method == "POST":
        form = contactForm(request.POST, request.FILES)
        if form.is_valid():
            print(form.cleaned_data)
            file = form.cleaned_data["file"]
            with open("./my_first_app/upload/" + file.name, "wb+") as destination:
                for chunk in file.chunks():
                    destination.write(chunk)
            render(request, "./my_first_app/django_form.html", {"form": form})
    else:
        form = contactForm()
    return render(request, "./my_first_app/django_form.html", {"form": form})


def StudentForm(request):
    if request.method == "POST":
        form = StudentData(request.POST, request.FILES)
        if form.is_valid():
            print(form.cleaned_data)
        # If the form is invalid, it should just fall through and render with errors
    else:
        form = StudentData()
    return render(request, "./my_first_app/django_form.html", {"form": form})


def passwordValidation(request):
    if request.method == "POST":
        form = PasswordValidationProject(request.POST, request.FILES)
        if form.is_valid():
            print(form.cleaned_data)
        # If the form is invalid, it should just fall through and render with errors
    else:
        form = PasswordValidationProject()
    return render(request, "./my_first_app/django_form.html", {"form": form})