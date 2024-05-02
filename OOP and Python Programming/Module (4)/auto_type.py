import pyautogui
from time import *
from random import *

sleep(2)
for i in range(0, 100):
    pyautogui.write(choice(['jan sottie bolchie ar emon hobe na', 'sorry jan!', 'amie tomake onek love koie jan, love you so much!', 'kokhon uthbe jan', 'tomer sathe kotha na bolle ghum hobe na, sara rat jege thakbo', 'jaaaaaannnnn!!!']), interval=0.001)
    pyautogui.press("enter")
