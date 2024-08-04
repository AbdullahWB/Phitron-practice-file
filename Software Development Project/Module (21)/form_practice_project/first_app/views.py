from django.shortcuts import render
from .forms import ExampleForm

# Create your views here.

def home(request):
    if request.method == 'POST':
        form = ExampleForm(request.POST)
        if form.is_valid():
            # process form data
            pass
    else:
        form = ExampleForm()

    return render(request, 'home.html', {'form': form})