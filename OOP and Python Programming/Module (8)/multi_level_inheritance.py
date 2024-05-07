class Vehicle:
    def __init__(self, name, price) -> None:
        self.name = name
        self.price = price
        
    def move(self):
        pass
    
class Buss(Vehicle):
    def __init__(self, name, price, sets) -> None:
        self.sets=sets
        super().__init__(name, price)