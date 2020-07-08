#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int tc;
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = abs(a[i]);
        if (i & 1) a[i] = -a[i];
    }
    int need = (n - 1) / 2;
    int ev = 0, od = 0;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? '\n' : ' ');
        if (i < n) {
            if (a[i + 1] - a[i] >= 0) ++ev;
            if (a[i + 1] - a[i] <= 0) ++od;
        }
    }
    assert(ev >= need && od >= need);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}