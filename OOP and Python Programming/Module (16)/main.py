from ride import Ride, RideMatching, RideRequest, RideShearing
from user import Driver, Rider
from vehicle import Car, Cng, Bike

uthiye_naw = RideShearing('uthiye_naw')
sauda = Rider("sauda binta busra", "sauda917828@hmail.com", 369501, "mog bajar", 1800)
uthiye_naw.add_rider(sauda)

abdullah = Driver("Mohammad Abdullah", "abdullah917828@gmail.com", 105963, "shantiogor")
uthiye_naw.add_driver(abdullah)
sauda.request_ride(uthiye_naw, "moner majhe", "car")
sauda.show_current_ride()
abdullah.reach_destination(sauda.current_ride)

print(uthiye_naw)