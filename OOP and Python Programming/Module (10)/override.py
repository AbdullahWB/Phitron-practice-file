class Person:
    def __init__(self, name, age, hight, weight) -> None:
        self.name = name
        self.age = age
        self.hight = hight
        self.weight = weight
        
    def eat(self):
        print('rice, meet, birianye, teharie, faluda')
        
    def exercise(self):
        raise NotImplementedError
        
        
class Programmer(Person):
    def __init__(self, name, age, hight, weight, language) -> None:
        self.language = language
        super().__init__(name, age, hight, weight)
        
    def eat(self):
        print('vegetables')
        
    def exercise(self):
        print('running') # This is way to override the exercise method
        
    def __add__(self, other):
        return self.age + other.age
    
    def __mul__(self, other):
        return self.weight * other.weight

    def __len__(self):
        return self.hight
    
    def __gt__(self, other):
        return self.age > other.age
        
abdullah = Programmer("Mohammad  Abdullah", 21, 182, 83, "c programming, c++, JavaScript, Python")
sauda = Programmer("sauda binta busra", 19, 170, 50, "c programming, c++, Python")

# print(abdullah)
abdullah.eat()
abdullah.exercise()

print(abdullah+sauda)
print(abdullah*sauda)
print(len(abdullah))
print(len(sauda))
print(sauda>abdullah)

# print([10,20,30]+[11,22,33])