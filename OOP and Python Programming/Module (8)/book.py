class Book:
    def __init__(self, name) -> None:
        self.name = name    
        
    def red(self):
        # print (f'red this book in the database')
        raise
        
class Physics(Book):
    def __init__(self, name, lab) -> None:
        self.lab = lab
        super().__init__(name)
    
    def red(self):
        return f'red this book in the database'
        
abdullahSir= Physics('abdullahSir', True)

print(issubclass(Physics, Book))
print(isinstance(abdullahSir, Physics))
print(isinstance(abdullahSir, Book))

abdullahSir.red()