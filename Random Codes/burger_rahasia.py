a = int(input())
b = input().split()
print(eval("*".join(b))%(10**9+7)-1)