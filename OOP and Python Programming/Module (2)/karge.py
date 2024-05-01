def popular(first,last,**additional):
    name= f'{first} {last}'
    # print(additional)
    for key,value in additional.items():
        print(f'{key} : {value}')
    return name

print(popular(first='mohammad',last='abdullah', title='programmers', type='verry goods'))


def display_person(**kwargs):
    for key,value in kwargs.items():
        print(f"{key}: {value}")


display_person(Name="Amir Khan", Age="45")