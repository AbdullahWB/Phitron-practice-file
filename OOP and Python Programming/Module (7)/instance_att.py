class Shop:
    shopping_mall= 'walmart'
    
    def __init__(self,buyer):
        self.buyer = buyer
        self.cart= [] # this cart is an instance attribute
        
    def add_to_cart(self, item):
        self.cart.append(item)
        

abdullah = Shop('Mohammad Abdullah')
abdullah.add_to_cart('chocolate')
abdullah.add_to_cart('rice')
abdullah.add_to_cart('bread')
abdullah.add_to_cart('chicken')
abdullah.add_to_cart('eggs')
abdullah.add_to_cart('nuts')
abdullah.add_to_cart('fruits')
abdullah.add_to_cart('vegetables')
print(abdullah.cart)