#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 2;

int n;
char s[N];
int pre[N];

void solve() {
    cin >> (s + 1);
    n = strlen(s + 1);
    vector<vector<int>> last(2, vector<int>(2));
    pre[0] = 1;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (s[i] == '?') continue;
        int x = s[i] - '0';
        int bit = (i % 2);
        pre[i] = max(pre[i], max(last[x][1 - bit], last[1 - x][bit]) + 1);
        last[x][bit] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long len = (i - pre[i] + 1);
        ans += len;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}