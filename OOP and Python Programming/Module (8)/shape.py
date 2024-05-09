from math import *

class Shape:
    def __init__(self, name) -> None:
        self.name = name
        
class Rectangular(Shape):
    def __init__(self, name, length, width) -> None:
        self.length = length
        self.width = width
        super().__init__(name)
        
    def area(self):
        return self.length * self.width

class Circle(Shape):
    def __init__(self, name, radius) -> None:
        self.radius = radius
        super().__init__(name)
        
    def area(self):
        return