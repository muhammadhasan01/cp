def main():
    s, b = input().split()
    b = int(b)

    ans = 0
    cur, pw, lst, length = 0, 1, b, 0
    for i in range(len(s) - 1, -1, -1):
        cur += pw * (int(s[i]) - 0)
        length += 1

        if cur > lst:
            cur -= pw * (int(s[i]) - 0)
            length -= 1

            if cur > lst:
                print("NO WAY")
                return

            lst = cur
            ans += 1

            cur = int(s[i])
            length = 1
            pw = 10
        else:
            pw *= 10

    if cur > lst:
        print("NO WAY")
        return

    print(ans)

if __name__ == "__main__":
    main()
