""" class Exam:
    def __init__(self,name):
        self.name=name
        self.score=0
        self.grade=None
        self.exam=None
        self.attendance=0
    
    def attendance(self, attend):
        if attend >0:
            self.attendance+=attend
    
    def in_exam(self):
        if self.attendance <= 74 :
            self.exam=False
            print(f'you are not allowed to in exam at this time you need up to 75% attendance for exam but you have just {self.attendance}%')
        elif self.attendance >= 75 :
            self.exam=True
            print(f'you are qualified for exam. congratulations!!! 😊😊')
            
    def marks(self, mark):
        if self.exam is True:
            if mark >= 80:
                self.score=mark
                self.grade='A'
                print(f'your score is {self.score} and grade is {self.grade}')
            elif mark >= 70:
                self.score=mark
                self.grade='B'
                print(f'your score is {self.score} and grade is {self.grade}')
            elif mark >= 60:
                self.score=mark
                self.grade='C'
                print(f'your score is {self.score} and grade is {self.grade}')
            elif mark >= 50:
                self.score=mark
                self.grade='D'
                print(f'your score is {self.score} and grade is {self.grade}')
            elif mark >= 40:
                self.score=mark
                self.grade='E'
                print(f'your score is {self.score} and grade is {self.grade}')
            elif mark < 40:
                self.score=mark
                self.grade='F'
                print(f'your score is {self.score} and grade is {self.grade}')
        else:
            print(f'you have no exam marks')
    
    

abdullah = Exam('Mohammad Abdullah')
attend= abdullah.attendance(70)
print(attend)
# abdullah.exam()
# print(abdullah.exam()) """


class Exam:
    def __init__(self, name):
        self.name = name
        self.score = 0
        self.grade = None
        self.exam = None
        self.attendance_percentage = 0

    def update_attendance(self, attendance):
        if attendance > 0:
            self.attendance_percentage += attendance

    def check_exam_eligibility(self):
        if self.attendance_percentage < 75:
            self.exam = False
            print(
                f"Sorry, {self.name}, you are not eligible for the exam. Your attendance is only {self.attendance_percentage}%."
            )
        else:
            self.exam = True
            print(f"Congratulations, {self.name}! You are eligible for the exam.")

    def assign_grade(self, mark):
        if self.check_exam_eligibility is True:
            grades = {80: "A", 70: "B", 60: "C", 50: "D", 40: "E"}
            for score, grade in grades.items():
                if mark >= score:
                    self.score = mark
                    self.grade = grade
                    print(f"Your score is {self.score} and grade is {self.grade}")
                    return
            self.score = mark
            self.grade = "F"
            print(f"Your score is {self.score} and grade is {self.grade}")
        else:
            print("you have no score")


# Test
abdullah = Exam("Mohammad Abdullah")
abdullah.update_attendance(70)
abdullah.check_exam_eligibility()
abdullah.assign_grade(75)
