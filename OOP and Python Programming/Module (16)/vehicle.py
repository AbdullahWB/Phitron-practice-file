from abc import *

class Vehicle(ABC):
    speed = {
        'car' : 50,
        'bike' : 60,
        'cng' : 15,
    }
    
    def __init__(self, vehicle_type, license_plate, rate) -> None:
        self.license_plate = license_plate
        self.rate = rate
        self.vehicle_type = vehicle_type
        super().__init__()
        
class Car(Vehicle):
    def __init__(self, vehicle_type, license_plate, rate) -> None:
        super().__init__(vehicle_type, license_plate, rate)

class Bike(Vehicle):
    def __init__(self, vehicle_type, license_plate, rate) -> None:
        super().__init__(vehicle_type, license_plate, rate)
        
class Cng(Vehicle):
    def __init__(self, vehicle_type, license_plate, rate) -> None:
        super().__init__(vehicle_type, license_plate, rate)