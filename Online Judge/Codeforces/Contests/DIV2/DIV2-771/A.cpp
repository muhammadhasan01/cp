#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0, x = 1; i < n; i++, x++) {
        if (p[i] != x) {
            int pos = -1;
            for (int j = i + 1; j < n; j++) {
                if (p[j] == x) {
                    pos = j;
                    break;
                }
            }
            assert(pos != -1);
            reverse(p.begin() + i, p.begin() + pos + 1);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}