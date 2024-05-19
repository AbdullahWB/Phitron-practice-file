class Menu:
    def __init__(self) -> None:
        self.items = []  # items database

    def add_menu_item(self, items):
        self.items.append(items)

    def find_item(self, item_name):
        for item in self.items:
            if item_name.lower() == item_name.lower():
                return item
            return None

    def remove_item(self, item_name):
        item = self.find_item(item_name)
        if item:
            self.items.remove(item)
            return f"{item} this item removed"
        else:
            return f"this item not found"

    def show_menu(self):
        print("*****Menu*****")
        print("Name\tPrice\tQuantity")
        for item in self.items:
            print(f"{item.name}\t{item.price}\t{item.quantity}")

