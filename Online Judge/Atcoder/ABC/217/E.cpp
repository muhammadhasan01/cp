#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    queue<int> qq;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            qq.emplace(x);
        } else if (tp == 2) {
            if (!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            } else {
                cout << qq.front() << '\n';
                qq.pop();
            }
        } else if (tp == 3) {
            while (!qq.empty()) {
                pq.emplace(qq.front());
                qq.pop();
            }
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