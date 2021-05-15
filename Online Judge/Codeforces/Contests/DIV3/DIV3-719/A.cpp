#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int n;
char a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        int k = -1;
        bool any = false;
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] != a[i]) {
                any = true;
            }
            if (a[j] == a[i]) {
                k = j;
                break;
            }
        }
        if (k == -1) continue;
        if (any) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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