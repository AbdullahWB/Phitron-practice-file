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

class ACBuss(Buss):
    def __init__(self, name, price, sets, air_cooler) -> None:
        self.air_cooler = air_cooler
        super().__init__(name, price, sets)
        
class track(Vehicle):
    def __init__(self, name, price, load_product) -> None:
        self.load_product = load_product
        super().__init__(name, price)
        
class ACtrack(track):
    def __init__(self, name, price, load_product, air_cooler) -> None:
        self.air_cooler = air_cooler
        super().__init__(name, price, load_product)
        