#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void outpos(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}

const int N = 1e3 + 5;

bool dp[N][N];
int ans[N];

void solve() {
    string str;
    getline(cin, str);
    stringstream SS(str); string s;
    int cnt = 0;
    int n = -1;
    while (SS >> s) {
        if (++cnt <= 2) continue;
        n = stoi(s);
    }
    assert(n != -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) dp[i][j] = 1;
        getline(cin, str);
        stringstream GG(str);
        cnt = 0;
        while (GG >> s) {
            if (++cnt <= 4) continue;
            int val = stoi(s);
            dp[i][val] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = i;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 2; j--) {
            if (!dp[i][j]) continue;
            swap(ans[j - 1], ans[j]);
        }
    }
    getline(cin, str);
    for (int i = 1; i <= n; i++) {
        char cur = (i == n ? '\n' : ' ');
        outpos(ans[i], cur);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    cin.ignore();
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}