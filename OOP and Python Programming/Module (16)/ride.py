from datetime import *
from vehicle import *

class RideShearing:
    def __init__(self, company_name) -> None:
        self.company_name = company_name
        self.riders = []
        self.drivers = []
        self.rides = []
        
    def add_rider(self, rider):
        self.riders.append(rider)
    
    def add_driver(self, driver):
        self.drivers.append(driver)
    
    def __str__(self) -> str:
        return f"Company Name: {self.company_name} with riders: {len(self.riders)} and Drivers: {len(self.drivers)} and Rides: {len(self.rides)}"

class Ride:
    def __init__(self, start_location, end_location, vehicle) -> None:
        self.start_location = start_location
        self.end_location = end_location
        self.driver = None
        self.rider = None
        self.start_time = None
        self.end_time = None
        self.estimated_fare = None
        self.vehicle = vehicle
        
    def set_diver(self, diver):
        self.diver = diver
    
    def start_ride(self):
        self.start_time = datetime.now()
        
    def end_ride(self):
        self.end_time = datetime.now()
        self.rider.wallet -= self.estimated_fare
        self.driver.wallet += self.estimated_fare
    
    def calculate_fare(self, distance, vehicle):
        fare_per_km = {
            'car' : 30,
            'bike' : 20,
            'cng' : 25
        }    
        return distance
    
    def __repr__(self) -> str:
        return f"Ride details. started {self.start_location} to {self.end_location}"
    
    
class RideRequest:
    def __init__(self, rider, end_location) -> None:
        self.rider = rider
        self.end_location = end_location
        
class RideMatching:
    def __init__(self, drivers) -> None:
        self.available_drivers = drivers
        
    def find_driver(self, ride_request, vehicle_type):
        if len(self.available_drivers)>0:
            print("Looking for driver .........!")
            driver = self.available_drivers[0]
            if vehicle_type == 'car':
                vehicle = Car('car', 'ABCD-E-239', 30)
            elif vehicle_type == 'bike':
                vehicle = Bike('Motor Bike', 'ABCD-E-508', 50)
            elif vehicle_type == 'cng':
                vehicle = Cng('CNG', 'ABCD-E-998', 20)
            ride = Ride(ride_request.rider.current_location, ride_request.end_location, vehicle)
            driver.accept_request(ride)
            return ride