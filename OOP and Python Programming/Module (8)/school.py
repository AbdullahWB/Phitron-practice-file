class School:
    def __init__(self, name, address) -> None:
        self.name = name
        self.address = address
        
class Department:
    def __init__(self, dpName, subject) -> None:
        self.dpName = dpName
        self.subject = subject
        
class Club:
    def __init__(self, clubName) -> None:
        self.clubName = clubName

class Student(School, Department, Club):
    def __init__(self, name, address, dpName, subject, clubName) -> None:
        Department.__init__(self, dpName, subject)
        Club.__init__(self, clubName)
        super().__init__(name, address)
