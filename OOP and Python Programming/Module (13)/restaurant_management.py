from abc import *


# make user abstract class to use other classes instead of abstract
class User(ABC):
    def __init__(self, name, email, phone, address) -> None:
        self.name = name
        self.email = email
        self.phone = phone
        self.address = address
        super().__init__()


class Customer(User):
    def __init__(self, name, email, phone, address) -> None:
        super().__init__(name, email, phone, address)
        self.cart = Order()

    def view_menu(self, restaurant):
        restaurant.menu.show_menu()

    def add_to_cart(self, restaurant, item_name, quantity):
        item = restaurant.menu.find_item(item_name)
        if item:
            item.quantity = quantity
            self.cart.add_item(item)
            print("Item added to cart")
        else:
            print("Item not found")

    def view_cart(self):
        print("*****View Cart*****")
        print("Name\tPrice\tQuantity")
        for item, quantity in self.cart.items.items():
            print(f"{item.name} {item.price} {quantity}")
        print(f"Total Price: {self.cart.total_price}")


class Order:
    def __init__(self) -> None:
        self.items = {}

    def add_item(self, item):
        if item in self.items:
            self.items[item] += item.quantity
        else:
            self.items[item] = item.quantity

    def remove(self, item):
        if item in self.item:
            del self.items[item]

    def total_price(self, item, quantity):
        return sum(item.price * quantity for item.quantity in self.items.items())

    def clear(self):
        self.items = {}


class Employee(User):
    def __init__(self, name, email, phone, address, age, designation, salary) -> None:
        self.age = age
        self.designation = designation
        self.salary = salary
        super().__init__(name, email, phone, address)


class Admin(User):
    def __init__(self, name, email, phone, address) -> None:
        super().__init__(name, email, phone, address)

    def add_employee(self, restaurant, employee):
        restaurant.add_employee(employee)

    def view_employee(self, restaurant):
        restaurant.view_employee()

    def add_new_item(self, restaurant, item):
        restaurant.menu.add_menu_item(item)

    def remove_item(self, restaurant, item):
        restaurant.menu.remove_item(item)


class Restaurant:
    def __init__(self, name) -> None:
        self.name = name
        self.employee = []  # this out data management
        self.menu = Menu()

    def add_employee(self, employee):
        self.employee.append(employee)

    def view_employee(self):
        print("Employee List !!")
        for emp in self.employee:
            print(emp.name, emp.email, emp.phone, emp.address)


class Menu:
    def __init__(self) -> None:
        self.items = []  # items database

    def add_menu_item(self, items):
        self.items.append(items)

    def find_item(self, item_name):
        for item in self.items:
            if item_name.lower() == item_name.lower():
                return item
            return None

    def remove_item(self, item_name):
        item = self.find_item(item_name)
        if item:
            self.items.remove(item)
            return f"{item} this item removed"
        else:
            return f"this item not found"

    def show_menu(self):
        print("*****Menu*****")
        print("Name\tPrice\tQuantity")
        for item in self.items:
            print(f"{item.name}\t{item.price}\t{item.quantity}")


class FoodItem:
    def __init__(self, name, price, quantity) -> None:
        self.name = name
        self.price = price
        self.quantity = quantity
        super().__init__()


new_muslim_house= Restaurant("New Muslim Restaurant")

mn=Menu()
item=FoodItem("pizza", 12.45, 10)
item2=FoodItem("burgur", 10, 30)
admin=Admin('mohammad', 'mohammad@gmail.com', 1234567890, 'chipa tolie, china')
admin.add_new_item(new_muslim_house,item)
admin.add_new_item(new_muslim_house,item2)

new_muslim_house.menu.show_menu()

customer_one=Customer('Mohammad Abdullah' ,'abdullah917828@gmail.com', '01632917828', 'nanchong, china')
customer_one_heart=Customer('sauda binta busra' ,'sauda@gmail.com', 1632917828, 'beijing, china')
customer_one.view_menu(new_muslim_house)