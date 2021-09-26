#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<char> s(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<int> pre(n + 2, -1), suf(n + 2, -1);
    vector<int> ans(n + 2, INF);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (s[i] == '1') {
            pre[i] = i;
            ans[i] = 0;
        } else if (s[i] == '0') {
            if (pre[i] != -1) {
                ans[i] = min(ans[i], i - pre[i]);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (s[i] == '1') {
            suf[i] = i;
            ans[i] = 0;
        } else if (s[i] == '0') {
            if (suf[i] != -1) {
                ans[i] = min(ans[i], suf[i] - i);
            }
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += ans[i];
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}