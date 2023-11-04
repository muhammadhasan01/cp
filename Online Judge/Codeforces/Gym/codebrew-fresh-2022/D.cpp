#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + 5);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        if (cnt[i] == m) {
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}