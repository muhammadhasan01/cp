def modus(lst):
    lst = list(map(int,lst))
    return max(sorted(set(lst))[::-1], key=lst.count)
a = input()
b = input().split()
print(modus(b))
