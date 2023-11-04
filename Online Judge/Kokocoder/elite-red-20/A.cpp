#include <bits/stdc++.h>

using namespace std;

const int N = 2E5 + 5;

void solve() {
    int q;
    cin >> q;
    vector<int> sizes(2);
    vector<int> pos(N, -1);
    vector<int> at(N, -1);
    while (q--) {
        char tp;
        cin >> tp;
        int x;
        cin >> x;
        if (tp == 'L') {
            at[x] = 0;
            pos[x] = ++sizes[0];
        } else if (tp == 'R') {
            at[x] = 1;
            pos[x] = ++sizes[1];
        } else if (tp == '?') {
            int idx = at[x];
            int minPop = min(sizes[idx] - pos[x], sizes[1 - idx] + pos[x] - 1);
            cout << minPop << '\n';
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}