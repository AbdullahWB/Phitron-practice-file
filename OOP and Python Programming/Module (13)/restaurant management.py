from abc import *

# make user abstract class to use other classes instead of abstract
class User(ABC):
    def __init__(self, name, email, phone, address) -> None:
        self.name = name
        self.email = email
        self.phone = phone
        self.address = address
        super().__init__()
        

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
            
class Restaurant:
    def __init__(self, name) -> None:
        self.name=name
        self.employee=[] #this out data management
        
    def add_employee(self, employee):
        self.employee.append(employee)
        
    def view_employee(self):
        print("Employee List !!")
        for emp in self.employee:
            print(emp.name, emp.email, emp.phone, emp.address)
            
class Menu:
    def  __init__(self) -> None:
        self.items=[] #items database
        
    def add_menu_item(self, items):
        self.items.append(items)
        
    def find_item(self, item_name):
        for item in self.items:
            if item_name.lower()==item_name.lower():
                return item
            return None
        
    def remove_item(self, item_name):
        item=self.find_item(item_name)
        if item:
            self.items.remove(item)
            return f'{item} this item removed'
        else:
            return f'this item not found'