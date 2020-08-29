#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int M = 1e9 + 7;

int n;
int a[N];
bool good[N];
int fact[N];
int C[N][N];

void init() {
    C[0][0] = 1;
    for (int i = 1; i < N; i++) {
        C[i][0] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
        }
        C[i][i] = 1;
    }
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        long long cur = ((1LL) * i * fact[i - 1]) % M;
        fact[i] = cur; 
    }
}

void upd(int& x, int y) {
    x = (x + y) % M;
    x = (x % M + M) % M;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) continue;
        good[a[i]] = 1;
    }
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) continue;
        ++res;
        if (good[i]) continue;
        ++cnt;
    }
    int ans = fact[res];
    for (int i = 1; i <= cnt; i++) {
        long long cur = ((1LL) * C[cnt][i] * fact[res - i]) % M;
        if (i & 1) cur = -cur;
        upd(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}