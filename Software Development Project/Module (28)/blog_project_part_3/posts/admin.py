from django.contrib import admin
from . import models
# Register your models here.

admin.site.register(models.Post)

# class CategoryAdmin(admin.ModelAdmin):
#     prepopulated_fields = {'slug': ('title',)}
#     list_display = ['title', 'slug',]

# admin.site.register(models.Category, CategoryAdmin)