from star_cinema import Hall

class User:
    def __init__(self, hall):
        self.hall = hall

    def view_show_list(self):
        self.hall.view_show_list()

    def book_seats(self, id, seat_list):
        try:
            self.hall.book_seats(id, seat_list)
        except ValueError as e:
            print(e)

    def view_available_seats(self, id):
        try:
            self.hall.view_available_seats(id)
        except ValueError as e:
            print(e)
