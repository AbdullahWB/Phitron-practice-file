from django.contrib import admin
from .models import Album

@admin.register(Album)
class AlbumAdmin(admin.ModelAdmin):
    list_display = ('album_name', 'musician', 'release_date', 'rating')
    search_fields = ('album_name', 'musician__first_name', 'musician__last_name')
    list_filter = ('release_date', 'rating')
