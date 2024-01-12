INF = int(1e9)

def main():
    s, b = input().split()
    b = int(b)

    n = len(s)
    if s == "0" and b == 0:
        print(0)
        return
    
    num = [[0] * 25 for _ in range(n)]
    for i in range(n):
        cur, pw = 0, 1
        for j in range(i, max(0, i - 22) - 1, -1):
            zz = cur + pw * (int(s[j]) - 0)
            if zz > b:
                break
            cur += pw * (int(s[j]) - 0)
            pw *= 10
            if s[j] == '0':
                num[i][i - j] = 0
            else:
                num[i][i - j] = cur;

    dp = [[INF] * 25 for _ in range(n)]
    for i in range(min(n, 25)):
        if num[i][i] != 0:
            dp[i][i] = 0

    for i in range(1, n):
        for j in range(i, max(1, i - 22) - 1, -1):
            if s[j] == '0' or num[i][i - j] == 0:
                continue
            for k in range(25):
                if num[j - 1][k] == 0:
                    continue
                if num[i][i - j] >= num[j - 1][k]:
                    dp[i][i - j] = min(dp[i][i - j], dp[j - 1][k] + 1)

    ans = INF
    for j in range(25):
        ans = min(ans, dp[n - 1][j])

    if ans == INF:
        print("NO WAY")
        return

    print(ans)

if __name__ == "__main__":
    main()
