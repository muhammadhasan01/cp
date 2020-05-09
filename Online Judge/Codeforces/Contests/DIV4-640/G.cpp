#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        if (n <= 3) {
            cout << -1 << '\n';
            continue;
        }
        deque<int> dq = {3, 1, 4, 2};
        int cur = 4;
        while (cur < n) {
            ++cur;
            if (cur & 1) {
                dq.push_front(cur);
            } else {
                dq.push_back(cur);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << dq[i] << (i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}