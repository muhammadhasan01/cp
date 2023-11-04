#include <bits/stdc++.h>

using namespace std;

const int K = 105;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int op = 0;
    for (int it = 0; it < K; it++) {
        int pos = -1;
        int sum = 0;
        int mul = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                pos = i;
            }
            sum += a[i];
            mul *= a[i];
        }
        if (sum >= 0 && mul == 1) {
            cout << op << '\n';
            return;
        }
        a[pos] = 1;
        ++op;
    }
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