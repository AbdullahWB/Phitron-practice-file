from menu import Menu

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
