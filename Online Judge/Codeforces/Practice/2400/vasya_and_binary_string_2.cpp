#include <bits/stdc++.h>

using namespace std;

const int K = 2;
const int N = 105;
const long long INF = 1e16;

int n;
char s[N];
int a[N];
long long dp[N][N][N];

long long get_ans(int l, int r, int p) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        return a[p];
    }
    long long& res = dp[l][r][p];
    if (res != 0) {
        return res;
    }
    res = a[p] + get_ans(l + 1, r, 1);
    for (int i = l + 1; i <= r; i++) {
        if (s[i] == s[l]) {
            res = max(res, get_ans(l + 1, i - 1, 1) + get_ans(i, r, p + 1));
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << get_ans(1, n, 1) << '\n';
    
    return 0;
}