class Phone:
    manufacturer = 'china'
    
    def __init__(self, owner, brand, price):
        self.owner = owner
        self.brand = brand
        self.price = price
        

my_phone=Phone('Mohammad Abdullah', 'xiaomi', 2000)
print(my_phone.owner, my_phone.brand, my_phone.price)