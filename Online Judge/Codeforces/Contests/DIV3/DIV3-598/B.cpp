#include <bits/stdc++.h>

using namespace std;

int q, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        deque<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int j = 0;
        while (j < n - 1) {
            int mini = 1e9, pos = -1;
            for (int i = j; i < n; i++) {
                if (v[i] < mini) {
                    mini = v[i];
                    pos = i;
                }
            }
            if (pos == j) {
                j++;
            } else {
                v.erase(v.begin() + pos);
                v.insert(v.begin() + j, mini);
                j = pos;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << v[i - 1] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
