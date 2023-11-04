#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> s(n), e(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }
    vector<int> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }
    vector<int> y(k);
    for (int i = 0; i < k; i++) {
        cin >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int posX = -1;
        {
            int l = 0, r = m - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (x[mid] <= s[i]) {
                    l = mid + 1;
                    posX = mid;
                } else {
                    r = mid - 1;
                }
            }
        }
        int posY = -1;
        {
            int l = 0, r = k - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (y[mid] >= e[i]) {
                    r = mid - 1;
                    posY = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        if (posX == -1 || posY == -1) {
            continue;
        }
        ans = min(ans, y[posY] - x[posX]);
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
    
    return 0;
}