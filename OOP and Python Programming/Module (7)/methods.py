class phone:
    name='mi phone'
    color= 'red'
    owner= 'mohammad abdullah'
    age='1 year old'
    price= 2000
    feature= ['camera', 'speaker', 'FM', 'call']
    
    def call(self):
        print('calling phone one a person....')
        
    def send_sms(self, phone, sms):
        text=f'send sms to {phone} and massage id {sms}'
        return text
    

my_phone=phone()
print(my_phone.feature)
my_phone.call()
text= my_phone.send_sms(1223344565, 'I love you but you don\'t')
print(text)