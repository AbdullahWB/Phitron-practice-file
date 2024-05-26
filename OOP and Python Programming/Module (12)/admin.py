from star_cinema import Hall

class Admin:
    def __init__(self, hall):
        self.hall = hall

    def entry_show(self, id, movie_name, time):
        self.hall.entry_show(id, movie_name, time)

    def view_show_list(self):
        self.hall.view_show_list()

    def view_available_seats(self, id):
        self.hall.view_available_seats(id)
