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