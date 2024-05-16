class Star_Cinema:
    hall_list = []
    
    @classmethod
    def entry_hall(self, hall):
        self.hall_list.append(hall)
        
class Hall(Star_Cinema):
    def __init__(self, rows, cols, hall_no) -> None:
        self.__seats={}
        self.__show_list=[]
        self.__rows=rows
        self.__cols=cols
        self.__hall_no=hall_no
        Star_Cinema.entry_hall(self)
        super().__init__()
        
    def entry_show(self, id, movie_name, time):
        show_info=(id, movie_name, time)
        self.__show_list.append(show_info)
        self.__seats[id] = [['free' for col in range(self.__cols)] for row in range(self.__rows)]
        
    def book_seats(self, id, seat_list):
        if id not in self.__seats:
            raise ValueError(f'No show have been found for this {id} identifier')
        
        for row,col in seat_list:
            if row>=self.__rows or col>=self.__cols:
                raise ValueError(f'No more seats have in this ({row},{col}). and out of range')
            if self.__seats[id][row][col]!='free':
                raise ValueError(f'seats have booked already in this ({row},{col})')
            self.__seats[id][row][col]='booked'
            
    def view_show_list(self):
        for show in self.__show_list:
            print(f'In this ID: {show[0]}, Movie: {show[1]}, Time: {show[2]}')
        
    def view_available_seats(self, id):
        if id not in self.__seats:
            raise ValueError(f'No more show with fount in this ID: {id}')
        available_seats = []
        for row in range(self.__rows):
            for col in range(self.__cols):
                if self.__seats[id][row][col]=='free':
                    available_seats.append((row,col))
        print(f'Available seats for show {id}: {available_seats}')
    


pagla_hall = Hall(5, 5, "H1")

pagla_hall.entry_show("S1", "den the day", "01:00")
pagla_hall.entry_show("S2", "rajkumer", "02:00")
pagla_hall.entry_show("S3", "oraj kumar", "05:00")
pagla_hall.entry_show("S4", "KGF new verson", "03:00")
pagla_hall.entry_show("S5", "love you python", "08:00")


pagla_hall.view_show_list()


pagla_hall.book_seats("S1", [(0, 0), (0, 1)])

pagla_hall.book_seats("S2", [(0, 0), (0, 1)])
seats_to_book = [(1, 1), (1, 2), (1, 3)] 
pagla_hall.book_seats("S2", seats_to_book)

pagla_hall.book_seats("S3", [(0, 0), (0, 1)])

pagla_hall.book_seats("S4", [(0, 0), (0, 1)])

pagla_hall.book_seats("S5", [(0, 0), (0, 1)])



pagla_hall.view_available_seats("S1")
pagla_hall.view_available_seats("S2")
pagla_hall.view_available_seats("S3")
pagla_hall.view_available_seats("S4")
pagla_hall.view_available_seats("S5")
