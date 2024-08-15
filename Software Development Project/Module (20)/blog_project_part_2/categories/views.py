from django.shortcuts import render, redirect
from . import forms
# Create your views here.

def add_categories(request):
    if request.method == 'POST':
        category_form = forms.CategoryFrom(request.POST)
        if category_form.is_valid():
            category_form.save()
            return redirect('add_categories')
    else:
        category_form = forms.CategoryFrom()
    return render(request, 'categories/index.html', {'form': category_form})