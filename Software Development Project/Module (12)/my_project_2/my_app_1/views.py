from django.shortcuts import render


# Create your views here.
def home(request):
    d = {
        "name": "Mohammad Abdullah",
        "age": 20,
        "email": "abdul@",
        "phone": "01711111111",
        "address": "Dhaka, Bangladesh",
        "website": "https://www.google.com",
        "facebook": "https://www.facebook.com",
        "list": ["python", "is", "best"],
        "course": [
            {
                "id": 1,
                "name": "Python",
                "price": 10000,
                "discount": 1000,
            },
            {
                "id": 2,
                "name": "Django",
                "price": 20000,
                "discount": 2000,
            },
            {
                "id": 3,
                "name": "Flask",
                "price": 30000,
                "discount": 3000,
            },
            {
                "id": 4,
                "name": "JavaScript",
                "price": 40000,
                "discount": 4000,
            },
        ],
    }
    return render(request, "my_app_1/home.html", d)
