""" def split_balanced_string(s):
    count = 0
    balanced_strings = []
    balance = 0
    
    current_string = ""
    for char in s:
        current_string += char
        if char == 'L':
            balance += 1
        else:
            balance -= 1
            
        if balance == 0:
            count += 1
            balanced_strings.append(current_string)
            current_string = ""
    
    return count, balanced_strings

# Example usage:
s = input().strip()
count, balanced_strings = split_balanced_string(s)

print(count)
for string in balanced_strings:
    print(string)

 """

def split_balanced_str(str):
    count=0
    balanced_str=[]
    balance=0
    
    current_str=""
    
    for char in str:
        current_str+=char
        if char=='L':
            balance+=1
        else:
            balance-=1
        
        if balance==0:
            count+=1
            balanced_str.append(current_str)
            current_str=""
    
    return count, balanced_str


str = input().strip()
count, balanced_str= split_balanced_str(str)

print(count)
for  string in balanced_str:
    print(string)