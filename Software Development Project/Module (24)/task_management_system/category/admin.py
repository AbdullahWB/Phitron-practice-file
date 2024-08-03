from django.contrib import admin
from .models import TaskCategory

@admin.register(TaskCategory)
class TaskCategoryAdmin(admin.ModelAdmin):
    list_display = ('name',)
    search_fields = ('name',)
