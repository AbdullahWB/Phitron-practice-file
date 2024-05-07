""" import pyautogui
from time import *

# sleep(2)
# for i in range(0, 100):
#     pyautogui.write(, interval=0.001)
#     pyautogui.press("enter")
n=int(input("Enter Your Number: "))
pyautogui.write( , interval=0.25)
for i in range(0, n):
    for j in range(0, i+1):
        print('#',end='')
    print()
    
 """
import pyautogui
from time import sleep

n = int(input("Enter Your Number: "))
sleep(2)
for i in range(1, n + 1):
    line = '#' * i
    pyautogui.typewrite(line + '\n', interval=0.25)

sleep(2)
#
##
###
####
#####

