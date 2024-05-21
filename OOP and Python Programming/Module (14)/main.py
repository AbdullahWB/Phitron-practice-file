from school import School 
from person import Student, Teacher
from subject import Subject
from classroom import ClassRoom


school = School("CWNU", "China")

eight = ClassRoom("Eight")
nine = ClassRoom("Nine")
ten = ClassRoom("Ten")

school.add_classroom(eight)
school.add_classroom(nine)
school.add_classroom(ten)

rahime = Student("Rahime", eight)
karime = Student("Karime", nine)
fahime = Student("Fahime", ten)
hamime = Student("Hamime", ten)


school.student_admission(rahime)
school.student_admission(karime)
school.student_admission(fahime)
school.student_admission(hamime)


abul = Teacher("Abul Khan")
babul = Teacher("babul Khan")
kabul = Teacher("kabul Khan")


bangla = Subject("Bangla", abul)
english = Subject("English", abul)
math = Subject("Math", babul)
ict = Subject("ict", kabul)


eight.add_subject(bangla)
eight.add_subject(english)
nine.add_subject(bangla)
nine.add_subject(english)
nine.add_subject(math)
ten.add_subject(bangla)
ten.add_subject(english)
ten.add_subject(math)
ten.add_subject(ict)

eight.take_semester_final_exam()

print(school)