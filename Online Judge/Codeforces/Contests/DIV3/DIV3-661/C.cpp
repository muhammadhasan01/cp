#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int val = 2; val <= 2 * n; val++) {
        vector<int> cnt(n + 1);
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            int j = val - a[i];
            if (1 <= j && j <= n && cnt[j]) {
                ++cur, --cnt[j];
            } else {
                cnt[a[i]]++;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--)
        solve();

    return 0;
}