def min_removals(n, a):
    max_value = max(map(int, a))
    count = [0] * (max_value + 1) 
    for num in a:
        count[int(num)] += 1
    
    removals = 0
    for i in range(1, len(count)):
        if count[i] > i:
            removals += count[i] - i 
    
    return removals

n = int(input())
a = input().strip().split() 

print(min_removals(n, a))
