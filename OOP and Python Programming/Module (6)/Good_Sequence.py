from collections import Counter

def min_removals(n, a):
    freq = Counter(a)
    removals = 0
    for num, count in freq.items():
        if count > num:
            removals += count - num
    return removals

n = int(input())
a = list(map(int, input().split()))

print(min_removals(n, a))
