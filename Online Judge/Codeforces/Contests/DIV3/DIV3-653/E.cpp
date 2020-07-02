#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v[4];
    vector<int> len(4);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        int cur = ((a & 1) << 1) + (b & 1);
        if (cur == 0) continue;
        sum += t;
        v[cur].emplace_back(t);
        len[cur]++;
    }
    if (len[1] + len[3] < k || len[2] + len[3] < k) {
        puts("-1");
        return 0;
    }
    vector<int> pre[4];
    for (int i = 1; i <= 3; i++) sort(v[i].begin(), v[i].end(), greater<int>());
    for (int i = 1; i <= 2; i++) {
        pre[i].resize(len[i]);
        for (int j = 0; j < len[i]; j++) {
            if (j) pre[i][j] = pre[i][j - 1];
            pre[i][j] += v[i][j];
        }
    }
    int ans = 2e9;
    int val = 0;
    for (int sz = 0; sz <= len[3]; sz++) {
        if (sz) val += v[3][sz - 1];
        int curval = val;
        bool ok = true;
        for (int j = 1; j <= 2; j++) {
            int cursz = len[j] + len[3] - sz - k;
            if (cursz > len[j] || cursz < 0) {
                ok = false;
                break;
            }
            if (cursz) curval += pre[j][cursz - 1];
        }
        if (!ok) continue;
        curval = sum - curval;
        ans = min(ans, curval);
    }
    cout << ans << '\n';

    return 0;
}