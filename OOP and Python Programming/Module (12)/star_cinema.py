class Star_Cinema:
    hall_list = []
    
    @classmethod
    def entry_hall(cls, hall):
        cls.hall_list.append(hall)

class Hall(Star_Cinema):
    def __init__(self, rows, cols, hall_no) -> None:
        self.__seats = {}
        self.__show_list = []
        self.__rows = rows
        self.__cols = cols
        self.__hall_no = hall_no
        Star_Cinema.entry_hall(self)
        super().__init__()
        
    def entry_show(self, id, movie_name, time):
        show_info = (id, movie_name, time)
        self.__show_list.append(show_info)
        self.__seats[id] = [['free' for col in range(self.__cols)] for row in range(self.__rows)]
        
    def book_seats(self, id, seat_list):
        if id not in self.__seats:
            raise ValueError(f'No show found with this ID: {id}')
        
        for row, col in seat_list:
            if row >= self.__rows or col >= self.__cols:
                raise ValueError(f'Seat ({row},{col}) is out of range...')
            if self.__seats[id][row][col] != 'free':
                raise ValueError(f'Seat ({row},{col}) is already booked...')
            self.__seats[id][row][col] = 'booked...'
            
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





hall_no = input("Enter hall number: ")
rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))
hall = Hall(rows, cols, hall_no)

while True:
    print("\n1. Enter a show...")
    print("2. View show list...")
    print("3. Book seats...")
    print("4. View available seats...")
    print("5. Exit...")
    choice = int(input("Choose an option: "))

    if choice == 1:
        id = input("Enter show ID: ")
        movie_name = input("Enter movie name: ")
        time = input("Enter show time: ")
        hall.entry_show(id, movie_name, time)
    elif choice == 2:
        hall.view_show_list()
    elif choice == 3:
        id = input("Enter show ID: ")
        seat_list = []
        n = int(input("Enter number of seats to book: "))
        for _ in range(n):
            row = int(input("Enter row number: "))
            col = int(input("Enter column number: "))
            seat_list.append((row, col))
        try:
            hall.book_seats(id, seat_list)
        except ValueError as e:
            print(e)
    elif choice == 4:
        id = input("Enter show ID: ")
        try:
            hall.view_available_seats(id)
        except ValueError as e:
            print(e)
    elif choice == 5:
        break
    else:
        print("Invalid choice. Please try again....")
