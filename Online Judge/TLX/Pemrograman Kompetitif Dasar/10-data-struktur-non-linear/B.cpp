#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            pq.emplace(x);
        } else if (tp == 2) {
            cout << pq.top() << '\n';
        } else if (tp == 3) {
            pq.pop();
        }
    }
    
    return 0;
}