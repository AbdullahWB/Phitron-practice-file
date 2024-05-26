class Star_Cinema:
    hall_list = []
    
    @classmethod
    def entry_hall(cls, hall):
        cls.hall_list.append(hall)

class Hall(Star_Cinema):
    def __init__(self, rows, cols, hall_no):
        self.__seats = {}
        self.__show_list = []
        self.__rows = rows
        self.__cols = cols
        self.__hall_no = hall_no
        Star_Cinema.entry_hall(self)
        
    def entry_show(self, id, movie_name, time):
        show_info = (id, movie_name, time)
        self.__show_list.append(show_info)
        self.__seats[id] = [['free' for col in range(self.__cols)] for row in range(self.__rows)]
        
    def book_seats(self, id, seat_list):
        if id not in self.__seats:
            raise ValueError(f'No show found with this ID: {id}')
        
        for row, col in seat_list:
            if row >= self.__rows or col >= self.__cols:
                raise ValueError(f'Seat ({row},{col}) is out of range.')
            if self.__seats[id][row][col] != 'free':
                raise ValueError(f'Seat ({row},{col}) is already booked.')
            self.__seats[id][row][col] = 'booked'
            
    def view_show_list(self):
        for show in self.__show_list:
            print(f'ID: {show[0]}, Movie: {show[1]}, Time: {show[2]}')
        
    def view_available_seats(self, id):
        if id not in self.__seats:
            raise ValueError(f'No show found with this ID: {id}')
        available_seats = []
        for row in range(self.__rows):
            for col in range(self.__cols):
                if self.__seats[id][row][col] == 'free':
                    available_seats.append((row, col))
        print(f'Available seats for show {id}: {available_seats}')
