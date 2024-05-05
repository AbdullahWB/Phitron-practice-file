class Calculator:
    brand='casio MS1293'
    def add(self, num1, num2):
        return num1 + num2
    
    def sub(self, num1, num2):
        return num1 - num2
    
    def div(self, num1, num2):
        return num1 // num2
    
    def mul(self, num1, num2):
        return num1 * num2
    
    def divmod(self, num1, num2):
        return num1 % num2
    
    
    
my_calculator = Calculator()
print('my calculator', my_calculator.brand)
print('number of addition',my_calculator.add(10,10))
print('number of sub',my_calculator.sub(80,10))
print('number of multi',my_calculator.mul(10,10))
print('number of div',my_calculator.div(40,5))
print('number of mod',my_calculator.divmod(36,7))