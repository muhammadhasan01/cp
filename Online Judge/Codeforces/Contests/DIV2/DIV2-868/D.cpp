#include <bits/stdc++.h>

using namespace std;

const int K = 3;

char getChar(int num) {
    return (char) (int('a') + num);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> x[i];
    }
    vector<int> c(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> c[i];
    }
    vector<int> d(k + 1);
    for (int i = 1; i <= k; i++) {
        d[i] = x[i] - c[i];
        if (d[i] < 0) {
            cout << "NO" << '\n';
            return;
        }
        if (d[i - 1] > d[i]) {
            cout << "NO" << '\n';
            return;
        }
    }
    string ans = "abc";
    int dumb = 0;
    int now = 3;
    for (int i = 1; i <= k; i++) {
        int need = d[i] - d[i - 1];
        for (int rep = 0; rep < need; rep++) {
            ans += getChar(dumb % K);
            dumb++;
        }
        int len = (int) ans.size();
        if (len > x[i]) {
            cout << "NO" << '\n';
            return;
        }
        if (len == x[i]) {
            continue;
        }
        for (int rep = 0; rep < x[i] - len; rep++) {
            ans += getChar(now);
        }
        now++;
    }
    cout << "YES" << '\n';
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}