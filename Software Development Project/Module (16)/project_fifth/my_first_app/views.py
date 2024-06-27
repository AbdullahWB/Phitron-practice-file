from django.shortcuts import render


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
