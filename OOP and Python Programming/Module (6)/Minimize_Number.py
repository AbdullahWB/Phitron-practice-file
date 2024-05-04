""" def max_operations(n, arr):
    operations = 0
    while all(num % 2 == 0 for num in arr):
        arr = [num // 2 for num in arr]
        operations += 1
    return operations


n = int(input())
arr = list(map(int, input().split()))

print(max_operations(n, arr))
 """
 
def max_operations(arr):
    operations=0
    while all(num % 2==0 for num in arr):
        arr = [num // 2 for num in arr]
        operations += 1
    return operations
 
n= int(input()) # not use this
arr = list(map(int, input().split()))
print(max_operations(arr))
