"""
!composition vs inheritance in python

Choosing Between Inheritance and Composition in Python
Python, as an object oriented programming language, supports both inheritance 
and composition.
You saw that inheritance is best used to model an is a relationship, whereas
composition models a has a relationship.

Sometimes, it's hard to see what the relationship between two classes should
be, but you can follow these guidelines:

	Use inheritance over composition in Python to model a clear is a 
    relationship. First, justify the relationship between the derived
    class and its base. Then, reverse the relationship and try to justify it. 
    If you can justify the relationship in both directions, then you should
    not use inheritance between them.

	Use inheritance over composition in Python to leverage both the interface
    and implementation of the base class.

	Use inheritance over composition in Python to provide mixin features to
    severalunrelated classes when there is only one implementation of that
    feature.

	Use composition over inheritance in Python to model a has a relationship
    that leverages the implementation of the component class.

	Use composition over inheritance in Python to create components that can
    be reused by multiple classes in your Python applications.

	Use composition over inheritance in Python to implement groups of 
    behaviors and policies that can be applied interchangeably to other 
    classes to customize their behavior.

	Use composition over inheritance in Python to enable run-time behavior
    changes without affecting existing classes.
"""

class CPU:
    def __init__(self, cores) -> None:
        self.cores = cores
        
class RAM:
    def __init__(self, memory) -> None:
        self.memory = memory
        
class HDD:
    def __init__(self, storage) -> None:
        self.storage = storage

class Computer:
    def __init__(self, cores, memory, storage) -> None:
        self.cpu = CPU(cores)
        self.ram = RAM(memory)
        self.hdd = HDD(storage)
        
asus = Computer(8, 16, 512)