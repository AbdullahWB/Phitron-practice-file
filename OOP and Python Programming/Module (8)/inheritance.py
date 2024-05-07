class Gadget:
    def __init__(self, brand, price, color, origin) -> None:
        self.brand = brand
        self.price = price
        self.color = color
        self.origin = origin
    
    def run(self):
        return f'Running laptop: {self.brand}'
    
    
class Laptop:
    def __init__(self, memory, ssd) -> None:
        self.memory = memory
        self.ssd = ssd
        
    def coding(self):   
        return f'learning programming and coding on laptop!!'
    

class Phone:
    def __init__(self, dual_sim) -> None:
       self.dual_sim = dual_sim
       
    def phone_call(self, number, text):
        return f'sending ssm to: {number} with text: {text}'
    
    def __repr__(self) -> str:
        return f'phone: {self.dual_sim}'
    

class Camera:
    def __init__(self, pixel) -> None:
        self.pixel = pixel
        
    def change_lens(self):
        pass
    

#inheritance ->

