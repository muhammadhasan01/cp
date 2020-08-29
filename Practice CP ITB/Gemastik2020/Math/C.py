n = int(input())
res, val, cur = 0, 1, 1
for i in range(7):
    val *= (n - i)
    cur *= (i + 1)
    if i >= 4:
        res += val // cur
print(int(res))

