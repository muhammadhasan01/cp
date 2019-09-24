#include <bits/stdc++.h>
using namespace std;

int q;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }
        int last = 0;
        bool ok = false;
        while (!pq.empty()) {
            int cur = pq.top();
            pq.pop();
            if (cur == 2048) {
                puts("YES");
                ok = true;
                break;
            } else if (cur > 2048) break;
            if (cur == last) {
                pq.push(2 * cur);
                last = 0;
            } else {
                last = cur;
            }
        }
        if (ok) continue;
        puts("NO");
    }

    return 0;
}
