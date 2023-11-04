#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int p[N];

void solve() {
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
        cout << "YES" << '\n';
        return;
    }
    int small = p[n];
    cout << (small <= m ? "NO" : "YES") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (p[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            p[j] = (p[j] == 0 ? i : p[j]);
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}