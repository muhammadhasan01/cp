a = int(input())
for i in range(1,a+1):
    if i%10 != 0 and i != 42:
        print(i)
    if i >= 42:
        print("ERROR")
        break

