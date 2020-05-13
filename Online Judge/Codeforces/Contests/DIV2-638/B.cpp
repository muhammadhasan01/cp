#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int n, k;
int a[N], ans[N * N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        vector<int> cnt(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int uniq = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 0) {
                uniq++;
            }
        }
        if (uniq > k) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            if (cnt[a[i]] > 0) {
                cnt[a[i]] = 0;
                v.push_back(a[i]);
            }
        }
        int len = v.size();
        for (int i = 0; i < k; i++) {
            for (int j = i; j < n * k; j += k) {
                ans[j] = v[i % len];
            }
        }
        cout << n * k << '\n';
        for (int i = 0; i < n * k; i++) {
            cout << ans[i] << (i == n * k - 1 ? '\n' : ' ');
        }
    }

    return 0;
}