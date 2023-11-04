#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int p[N];

void solve() {
    int l, r;
    cin >> l >> r;
    for (int x = l; x <= r; x++) {
        if (p[x] == x) {
            continue;
        }
        cout << p[x] << ' ' << (x - p[x]) << '\n';
        return;
    }
    cout << -1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    p[1] = 1;
    for (int i = 2; i < N; i++) {
        if (p[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            p[j] = i;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}