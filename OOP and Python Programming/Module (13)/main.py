from foodItem import FoodItem
from menu import Menu
from order import Order
from restaurant import Restaurant
from useers import Admin, Customer, Employee


new_muslim_house= Restaurant("New Muslim Restaurant")

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
        elif choice == 2:
            item_name = input("Enter your item name: ")
            item_quantity= int(input("Enter your item quantity: "))
            customer.add_to_cart(new_muslim_house, item_name, item_quantity)
        elif choice == 3:
            customer.view_cart()
        elif choice == 4:
            customer.pay_bill()
        elif choice == 5:
            print("Thank you for visiting our restaurant")
            break
        else:
            print("Invalid choice Error 404")   
            


def admin_menu():
    name=input("Enter your name: ")
    email=input("Enter your email address: ")
    phone=input("Enter your phone number: ")
    address=input("Enter your address: ")
    admin=Admin(name=name, email=email, phone=phone, address=address)
    
    while True:
        print("Welcome {admin.name}!!")
        print("1. Add New Item...")
        print("2. Add New Employee...")
        print("3. View Employee...")
        print("4. View Item...")
        print("5. Delete Item...")
        print("5. Exit...")
        
        choice=int(input("Enter your choice: "))
        
        if choice == 1:
            item_name = input("Enter your item name: ")
            item_price= int(input("Enter your item price: "))
            item_quantity= int(input("Enter your item quantity: "))
            item= FoodItem(item_name, item_price, item_quantity)
            admin.add_new_item(new_muslim_house ,item)    
        elif choice == 2:
            name=input("Enter your name: ")
            phone=int(input("Enter your phone number: "))
            email=input("Enter your email address: ")
            designation=input("Enter your designation: ")
            age=int(input("Enter your age: "))
            salary=int(input("Enter your salary: "))
            address=input("Enter your address: ")
            employee=Employee(name, email, phone, address, age, designation, salary)
            admin.add_employee(new_muslim_house, employee) 
        elif choice == 3:
            admin.view_employee(new_muslim_house)
        elif choice == 4:
            admin.view_menu(new_muslim_house)
        elif choice == 5:
            item_name= input("Enter your item name: ")
            admin.remove_item(new_muslim_house, item_name)
        elif choice == 6:
            print("Thank you for visiting our restaurant")
            break
        else:
            print("Invalid choice Error 404")   
            
            

while True:
    print("1. Customer")
    print("2. Admin")
    print("3. Exit")
    
    choice=int(input("Enter your choice: "))
    
    if choice == 1:
        customer_menu()
    elif choice == 2:
        admin_menu()
    elif choice == 3:
        print("Thank you for visiting our restaurant")
        break
    else:
        print("Invalid choice Error 404")