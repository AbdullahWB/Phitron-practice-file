from django import forms


class contactForm(forms.Form):
    name = forms.CharField(label="user_name")
    file = forms.FileField(label="file")
    # email = forms.EmailField(label="user_email")
    # age = forms.IntegerField(label="user_age")
    # weights = forms.FloatField(label="user_weights")
    # balance = forms.DecimalField(label="user_balance")
    # check = forms.BooleanField(label="user_check")
    # birth_date = forms.DateField(
    #     label="User Birth Date", widget=forms.SelectDateWidget(years=range(1900, 2100))
    # )
    # appointments = forms.ChoiceField(
    #     label="User Appointments",
    #     choices=[
    #         ("1", "Consultation"),
    #         ("2", "Follow-up"),
    #         ("3", "Routine Check-up"),
    #         ("4", "Emergency"),
    #     ],
    # )
    # food = forms.MultipleChoiceField(
    #     label="Favorite Foods",
    #     choices=[
    #         ("pizza", "Pizza"),
    #         ("burger", "Burger"),
    #         ("pasta", "Pasta"),
    #         ("salad", "Salad"),
    #         ("sushi", "Sushi"),
    #     ],
    # )
