from django.db import models
from musicians.models import Musician

class Album(models.Model):
    album_name = models.CharField(max_length=200)
    musician = models.ForeignKey(Musician, on_delete=models.CASCADE, related_name='albums')
    release_date = models.DateField()
    rating = models.IntegerField(choices=[(i, str(i)) for i in range(1, 6)])

    def __str__(self):
        return self.album_name
