def popular(first,last,**additional):
    name= f'{first} {last}'
    # print(additional)
    for key,value in additional.items():
        print(f'{key} : {value}')
    return name

print(popular(first='mohammad',last='abdullah', title='programmers', type='verry goods'))