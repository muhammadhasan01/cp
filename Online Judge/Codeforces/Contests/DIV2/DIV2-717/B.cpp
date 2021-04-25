#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n;
int a[N];
int pre[N], suf[N];

void solve() {
    cin >> n;
    int XOR = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        XOR = (XOR ^ a[i]);
    }
    if (XOR == 0) {
        cout << "YES" << '\n';
        return;
    }
    pre[0] = suf[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] ^ a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = (suf[i + 1] ^ a[i]);
    }
    for (int i = 2; i <= n - 1; i++) {
        for (int j = i - 1; j >= 1; j--) {
            int lft = pre[j];
            int mid = (pre[i] ^ pre[j]);
            int rgt = (suf[i + 1]);
            if (lft == mid && mid == rgt) {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
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