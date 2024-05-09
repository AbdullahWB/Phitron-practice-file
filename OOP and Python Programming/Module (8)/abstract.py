from abc import *

class Animal(ABC):
    @abstractmethod
    def eat(self):
        print("I need to eat: ")
        
    @abstractmethod
    def move(self):
        print("I need to move: ")

class Monkey(Animal):
    def __init__(self, name) -> None:
        self.name=name
        self.category='Monkey'
        super().__init__()
        
    def eat(self):
        print("Hello I am a little monkey. My name is sabbir tanjil. I eading banana na na na banana na !!!!!")
        
    def move(self):
        print("Hello I move also branch of branch on tree")
        
layke=Monkey('layke-on-the-tree')
layke.eat()
layke.move()


""" Abstraction in oops is an essential feature of Object Oriented Programming, which implies only keeping the essentials and removing unnecessary information. Abstraction in OOPS is used to hide unnecessary information and display only necessary information to the users interacting. """