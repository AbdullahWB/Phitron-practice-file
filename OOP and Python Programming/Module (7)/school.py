class Student:
    def __init__(self, name, current_class, id):
        self.name = name
        self.current_class = current_class
        self.id = id
    
    def __repr__(self) -> str:
        return f'student name is {self.name} and student class is {self.current_class} student id is {self.id}'
    

class Teacher:
    def __init__(self, name, subject, id):
        self.name=name
        self.subject=subject
        self.id=id
        
    def __repr__(self) -> str:
        return f'Teacher name is {self.name} and he/she cover the subject is {self.subject} and teacher id is {self.id}'
    
class School:
    def __init__(self, name):
        self.name = name
        self.student=[]
        self.teacher=[]
        
    

abdullah= Student('Mohammad Abdullah', 13, 202322240356)
print(abdullah)



""" class A:
    def __init__(self, value):
        value = 3
        self.value = value

    def change(self):
        self.value = 12


ans = []
a = A(13)
ans.append(a.value)
a.change()
ans.append(a.value)
print(ans) """



""" class Phone:
    price = 12000
    color = 'blue'
    brand = 'samsung'

    def call(self):
        print('calling one person')

    def send_sms(self, phone, sms):
        text = f'Sending SMS to: {phone+5}'
        return text


my_phone = Phone()
result = my_phone.send_sms(41524, 'Missy, I missed to miss you')
print(result) """