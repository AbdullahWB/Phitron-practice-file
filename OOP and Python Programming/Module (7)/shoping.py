class Shopping():
    def __init__(self,name):
        self.name=name
        self.cart=[]
    
    def add_to_cart(self, item, quantity, price):
        product={'item':item, 'quantity':quantity, 'price':price}
        self.cart.append(product)
    
    def remove_from_cart(self, item):
        pass
    
    def update_cart(self, item, quantity, price):
        pass
    
    def checkout(self, amount):
        total=0
        for item in self.cart:
            total+= item['quantity'] * item['price']
        
        print(f'your total order amount is {total}$')
            
        if total > amount:
            print(f'you have not enough money to purchase you want to {total-amount}$ more money')
        else:
            print(f'you purchase this product successfully. you pay {amount}$ and this is your total order amount {total}$. You will back {amount-total}$ this amount')
            
abdullah = Shopping('Mohammad Abdullah')
abdullah.add_to_cart('murgie', 10, 7)
abdullah.add_to_cart('mach', 5, 15)
abdullah.add_to_cart('dim', 30, 1)
abdullah.add_to_cart('chal', 10, 3)

print(abdullah.cart)
abdullah.checkout(200)