#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    bool isSorted = true;
    deque<int> dq;
    vector<bool> ans(n);
    int L = -1, R = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (dq.empty()) {
            dq.emplace_back(x);
            ans[i] = 1;
        } else if ((int) dq.size() == 1) {
            if (x < dq.back()) {
                isSorted = false;
                L = x;
                R = dq.front();
            }
            dq.emplace_back(x);
            ans[i] = 1;
        } else {
            if (isSorted) {
                if (x >= dq.back()) {
                    dq.emplace_back(x);
                    ans[i] = 1;
                } else if (x <= dq.front()) {
                    dq.emplace_back(x);
                    isSorted = false;
                    L = x;
                    R = dq.front();
                    ans[i] = 1;
                }
            } else {
                if (L <= x && x <= R) {
                    dq.emplace_back(x);
                    ans[i] = 1;
                    L = x;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }   
    cout << '\n';
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