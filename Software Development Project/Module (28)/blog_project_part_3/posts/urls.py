"""
URL configuration for blog_project project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""

from django.urls import path, include
from . import views

urlpatterns = [
    # path('add_posts/', views.add_posts, name='add_posts'),
    path('add_posts/', views.AddPostCreateView.as_view(), name='add_posts'),
    # path('edit/<int:id>', views.edit_posts, name='edit_posts'),
    path('edit/<int:id>/', views.EditPostView.as_view(), name='edit_posts'),
    # path('delete/<int:id>', views.delete_posts, name='delete_posts'),
    path('delete/<int:id>/', views.DeletePostView.as_view(), name='delete_posts'),
    path('details/<int:id>/', views.DetailPostView.as_view(), name='details_posts'),
]
