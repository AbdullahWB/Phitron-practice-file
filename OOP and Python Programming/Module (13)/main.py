from foodItem import FoodItem
from menu import Menu
from order import Order
from restaurant import Restaurant
from useers import Admin, Customer, Employee


def customer_menu():
    name=input("Enter your name: ")
    email=input("Enter your email address: ")
    phone=input("Enter your phone number: ")
    address=input("Enter your address: ")
    customer=Customer(name=name, email=email, phone=phone, address=address)
    
    while True:
        print("Welcome {customer.name}!!")
        print("1. view menu...")
        print("2. Add item to cart...")
        print("3. view cart...")
        print("4. pay bill...")
        print("5. Exit...")
        
        choice=int(input("Enter your choice: "))
        
        if choice == 1:
            customer.view_menu()
        