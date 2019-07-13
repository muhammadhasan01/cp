def pal(a):
    return "YA" if a[::-1] == a else "BUKAN"
print(pal(input()))
"""
def pal(a):
    if len(a) == 1:
        return "YA"
    if a[0] == a[-1]:
        c = a[1:-1]
        return pal(c)
    else:
        return "BUKAN"
print(pal(input()))
"""
