#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
char s[N], a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    if (s[1] == '0' || s[n] == '0') {
        cout << "NO" << '\n';
        return;
    }
    vector<int> eq, neq;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            eq.emplace_back(i);
        } else if (s[i] == '0') {
            neq.emplace_back(i);
        }
    }
    if ((int) neq.size() % 2 != 0) {
        cout << "NO" << '\n';
        return;
    }
    int leq = (int) eq.size();
    for (int i = 0; i < leq; i++) {
        if (i < leq / 2) {
            a[eq[i]] = b[eq[i]] = '(';
        } else {
            a[eq[i]] = b[eq[i]] = ')';
        }
    }
    int lneq = (int) neq.size();
    for (int i = 0; i < lneq; i += 2) {
        a[neq[i]] = b[neq[i + 1]] = '(';
        a[neq[i + 1]] = b[neq[i]] = ')';
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        cout << b[i];
    }
    cout << '\n';
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