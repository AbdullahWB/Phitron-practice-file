from abc import *
from ride import *

class User(ABC):
    def __init__(self, name, email, nid) -> None:
        self.name = name
        self.email = email
        self.nid = nid
        self.wallet = 0
        super().__init__()
    
    @abstractmethod
    def display_profile(self):
        raise NotImplementedError
    

class Rider(User):
    def __init__(self, name, email, nid, current_location, initial_amount) -> None:
        self.current_ride = None
        self.current_location = current_location
        self.wallet = initial_amount
        super().__init__(name, email, nid)
        
    def display_profile(self):
        print(f"Rider: {self.name} and email {self.email}")
        
    def load_cash(self, amount):
        if amount > 0:
            self.wallet += amount
        else:
            print("Amount less than 0")
            
    def update_location(self, current_location):
        self.current_location = current_location
        
    def request_ride(self, ride_shearing, destination, vehicle_type):
        ride_request = RideRequest(self, destination)
        ride_matching = RideMatching(ride_shearing.divers)
        ride = ride_matching.find_driver(ride_request, vehicle_type)
        self.current_ride = ride
        print("YAH!! We got a ride")        
    
    def show_current_ride(self):
        print(self.current_ride)


class Driver(User):
    def __init__(self, name, email, nid, current_location) -> None:
        self.current_location = current_location
        self.wallet = 0
        super().__init__(name, email, nid)
        
    def display_profile(self):
        print(f"Driver: {self.name} and email {self.email}")
        
    def accept_ride(self, ride):
        ride.set_driver(self)
    