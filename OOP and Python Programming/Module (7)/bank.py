class Bank:
    def __init__(self, balance):
        self.balance = balance
        self.max_balance = 100000
        self.min_balance = 100
    
    def get_balance(self):
        print(self.balance)
    
    def deposit(self, amount):
        if amount>0 :
            self.balance += amount
            
    def withdraw(self, amount):
        if amount>self.max_balance:
            print(f'you can\'t withdraw more than {self.max_balance}')
        elif amount<self.min_balance:
            print(f'you can\'t withdraw less than {self.min_balance}')
        else:
            print(f'your withdraw amount is {amount}')
            self.balance -= amount
            print(f'your current amount is {self.get_balance()}')
            
            
ific=Bank(0)
ific.deposit(100000)
ific.get_balance()
ific.withdraw(499)
ific.deposit(200)
ific.get_balance()