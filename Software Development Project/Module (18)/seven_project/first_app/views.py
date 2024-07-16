from django.shortcuts import render
from first_app.forms import StudentForms

# Create your views here.


def home(request):
    # std = StudentForms()
    if request.method == "POST":
        form = StudentForms(request.POST)
        if form.is_valid():
            form.save(commit=True)
            print(form.cleaned_data)
    else:
        form = StudentForms()
    return render(request, "home.html", {'form': form})
