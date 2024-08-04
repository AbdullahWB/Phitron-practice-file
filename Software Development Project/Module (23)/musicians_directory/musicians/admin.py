from django.contrib import admin
from .models import Musician

@admin.register(Musician)
class MusicianAdmin(admin.ModelAdmin):
    list_display = ('first_name', 'last_name', 'email', 'instrument_type')
    search_fields = ('first_name', 'last_name', 'email')
    list_filter = ('instrument_type',)
