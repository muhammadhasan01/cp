#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int tc;
int n, k, d;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k >> d;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        unordered_map<int,int> m;
        int ans = 1e9, cur = 0;
        for (int i = 1, j = 1; i <= n - d + 1; i++) {
            while (j - i < d) {
                if (++m[a[j]] == 1) cur++;
                j++;
            }
            ans = min(ans, cur);
            if (--m[a[i]] == 0) cur--;
        }
        cout << ans << '\n';
    }

    return 0;
}
