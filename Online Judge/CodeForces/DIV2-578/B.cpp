#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int tc;
int n, m, k;
int h[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
        }
        if (n == 1) {
            cout << "YES" << '\n';
            continue;
        }
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (h[i] + k >= h[i + 1]) {
                m += min(h[i], h[i] + k - h[i + 1]);
            } else {
                int req = h[i + 1] - k - h[i];
                if (req > m) {
                    ok = false;
                    break;
                } else {
                    m -= req;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }


    return 0;
}
