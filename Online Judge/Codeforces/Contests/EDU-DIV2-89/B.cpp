#include <bits/stdc++.h>

using namespace std;

const int N = 2e2 + 5;

int tc;
int n, x, m;
int l[N], r[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> x >> m;
        int leftz = x, rightz = x;
        for (int i = 1; i <= m; i++) {
            cin >> l[i] >> r[i];
        }
        vector<bool> good(m + 5);
        l[0] = r[0] = x;
        good[0] = true;
        for (int i = 1; i <= m; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (!good[j]) continue;
                if (l[i] <= l[j] && l[j] <= r[i]) {
                    good[i] = true;
                    break;
                } else if (l[i] <= r[j] && r[j] <= r[i]) {
                    good[i] = true;
                    break;
                }
            }
            if (good[i]) {
                leftz = min(leftz, l[i]);
                rightz = max(rightz, r[i]);
            }
        }
        cout << rightz - leftz + 1 << '\n';
    }

    return 0;
}