class Shopping:
    cart=[] #class attribute #static attribute
    origin = 'china'
    
    def __init__(self,name, location):
        self.name = name  # instance attribute
        self.location = location
        
    def purchase(self, item, price, amount):
        remaining = amount - price
        print(f'buying:{item} for pricing:{price} and remaining:{remaining}')
    
    @classmethod
    def hudai_dekhie(self, item):
        print(f'hudai dekie kichu kinina, hudai dekhie berai:-> {item}')    
    
    @staticmethod
    def multiply(a,b):
        result= a * b
        print(f'multiplying result: {result}')
    
            
basundhara= Shopping('basun dhara','kono ek chiper modde')
basundhara.purchase('lungi', 222, 500)
basundhara.hudai_dekhie('pant')
Shopping.hudai_dekhie('new pant lungie')
Shopping.multiply(4,4)