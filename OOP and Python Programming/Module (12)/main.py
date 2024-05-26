from star_cinema import *
from admin import *
from user import *

def admin_interface(admin):
    while True:
        print("\n1. Enter a show")
        print("2. View show list")
        print("3. View available seats")
        print("4. Exit")
        choice = int(input("Choose an option: "))

        if choice == 1:
            id = input("Enter show ID: ")
            movie_name = input("Enter movie name: ")
            time = input("Enter show time: ")
            admin.entry_show(id, movie_name, time)
        elif choice == 2:
            admin.view_show_list()
        elif choice == 3:
            id = input("Enter show ID: ")
            admin.view_available_seats(id)
        elif choice == 4:
            break
        else:
            print("Invalid choice. Please try again.")

def user_interface(user):
    while True:
        print("\n1. View show list")
        print("2. Book seats")
        print("3. View available seats")
        print("4. Exit")
        choice = int(input("Choose an option: "))

        if choice == 1:
            user.view_show_list()
        elif choice == 2:
            id = input("Enter show ID: ")
            seat_list = []
            n = int(input("Enter number of seats to book: "))
            for _ in range(n):
                row = int(input("Enter row number: "))
                col = int(input("Enter column number: "))
                seat_list.append((row, col))
            user.book_seats(id, seat_list)
        elif choice == 3:
            id = input("Enter show ID: ")
            user.view_available_seats(id)
        elif choice == 4:
            break
        else:
            print("Invalid choice. Please try again.")

def main():
    hall_no = input("Enter hall number: ")
    rows = int(input("Enter number of rows: "))
    cols = int(input("Enter number of columns: "))
    hall = Hall(rows, cols, hall_no)

    print("\n1. Admin Interface\n2. User Interface\n3. Exit")
    choice = int(input("Choose an option: "))

    if choice == 1:
        admin = Admin(hall)
        admin_interface(admin)
    elif choice == 2:
        user = User(hall)
        user_interface(user)
    elif choice == 3:
        return
    else:
        print("Invalid choice")
main()
