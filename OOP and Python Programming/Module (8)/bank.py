# encapsulation --> hide details
# access modifiers: public, protected, privet

class Bank:
    def __init__(self, holder_name, initial_deposit) -> None:
        self.holder_name = holder_name #public attribute
        self._branch = 'Dhaka 1100' #protected attribute
        self.__balance = initial_deposit #private attribute

    def deposit(self, amount):
        self.__balance += amount
    
    def get_balance(self):
        return self.__balance
    
    def withdraw(self, amount):
        if amount<self.__balance:
            self.__balance = self.__balance - amount
            return amount
        else:
            return f'no money available!!!!'

abdullah = Bank('mohammad Abdullah', 10000)
print(abdullah.holder_name)
abdullah.holder_name = 'sauda binta busra'
abdullah.deposit(40000)
print(abdullah.get_balance())
print(abdullah.holder_name)
print(abdullah._Bank__balance)
