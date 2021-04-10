#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 1e3 + 5;

int n;
int ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < N; i++) {
        ans[i] = INF;
    }
    cin >> n;
    for (int bit = 0; bit < 10; bit++) {
        for (int val = 0; val <= 1; val++) {
            vector<int> q;
            for (int i = 1; i <= n; i++) {
                int b = ((i >> bit) & 1);
                if (b != val) continue;
                q.emplace_back(i);
            }
            int len = q.size();
            if (len == n || len == 0) continue;
            cout << len << endl;
            for (int i = 0; i < len; i++) {
                cout << q[i];
                if (i == len - 1)
                    cout << endl;
                else
                    cout << ' ';
            }
            for (int i = 1; i <= n; i++) {
                int mini;
                cin >> mini;
                int b = ((i >> bit) & 1);
                if (b == val) continue;
                ans[i] = min(ans[i], mini);
            }
        }
    }
    cout << -1 << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i == n)
            cout << endl;
        else
            cout << ' ';
    }

    return 0;
}