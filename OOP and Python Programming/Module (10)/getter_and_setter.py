class User:
    def __init__(self, name, age, salary) -> None:
        self._name = name
        self._age = age
        self.__salary = salary
    
    @property #getter without setter read only property
    def age(self):
        return self._age
    
    @property
    def salary(self):
        return self.__salary
    
    @salary.setter
    def salary(self, value):
        if value < 0:
            print(f'{value} is not a negative number')
        self.__salary += value
    
abdullah = User('Mohammad Abdullah', 21, 12000)
print(abdullah.age)
print(abdullah.salary)
abdullah.salary = 10000
print(abdullah.salary)