from django.contrib import admin
from .models import TaskModel


@admin.register(TaskModel)
class TaskAdmin(admin.ModelAdmin):
    list_display = ("taskTitle", "taskDescription", "is_completed", "task_assign_date")
    list_filter = ("is_completed", "task_assign_date")
    search_fields = ("taskTitle", "taskDescription")
