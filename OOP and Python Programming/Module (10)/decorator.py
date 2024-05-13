import math
import time

def timer(func):
    def inner(*args, **kwargs):
        print("inner function timer on")
        satr=time.time()
        # print(func)
        func(*args, **kwargs)
        print("inner function timer off")
        end=time.time()
        print(f"total time elapsed {end-satr}")
    return inner

# timer()()

@timer
def get_factorial(n):
    print("get factorial starting")
    factorial=math.factorial(n)
    print(f'{n} factorial is {factorial}')

get_factorial(1000)

# number=[6689502913449127057588118054090372586752746333138029810295671352301633557244962989366874165271984981308157637893214090552534408589408121859898481114389650005964960521256960000000000000000000000000000]
# for n in number:
#     for i,digit in enumerate(str(n)):
#         print(i)