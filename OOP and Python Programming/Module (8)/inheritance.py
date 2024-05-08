class Gadget:
    def __init__(self, brand, price, color, origin) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.origin = origin
    
    def run(self):
        return f'Running laptop: {self.brand}'
    
    
class Laptop(Gadget):
    def __init__(self, brand, price, color, origin, memory, ssd) -> None:
        self.memory = memory
        self.ssd = ssd
        super().__init__(brand, price, color, origin)
 
    def coding(self):   
        return f'learning programming and coding on laptop!!'
    

class Phone(Gadget):
    def __init__(self, brand, price, color, origin, dual_sim) -> None:
        self.dual_sim = dual_sim
        super().__init__(brand, price, color, origin)

    def phone_call(self, number, text):
        return f'sending ssm to: {number} with text: {text}'
    
    def __repr__(self) -> str:
        return f'phone: {self.dual_sim}'
    

class Camera(Gadget):
    def __init__(self, brand, price, color, origin, pixel) -> None:
        self.pixel = pixel
        super().__init__(brand, price, color, origin)
        
    def change_lens(self):
        pass 
    

#inheritance ->

