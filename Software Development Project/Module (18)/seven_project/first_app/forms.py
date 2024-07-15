from django import forms
from first_app.models import StudentModel

class StudentForms(forms.ModelForm):
    class Meta:
        model = StudentModel
        fields = '__all__'
        labels = {
            'name': 'Full Name',
        }
        widgets = {
            'roll' : forms.PasswordInput()
        }
        help_texts = {
            'name': 'Student Name',
        }
        error_messages = {
            'name' : {'required' : 'your name is required'}
         }