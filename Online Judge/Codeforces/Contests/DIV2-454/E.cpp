#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n, m;
int dp[N];
int need;
vector<int> res;

bool can(int x) {
    vector<int> v(n, 1);
    for (int i = 0; i < x; i++) v[i] = 0;
    do {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = dp[i];
        }
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                int val = temp[i];
                for (int j = n - 1; j >= 0; j--) {
                    if (val & (1 << j)) {
                        temp[j] |= val;
                    }
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (temp[i] != need) {
                flag = false;
                break;
            }
        }
        if (flag) {
            res.clear();
            for (int i = 0; i < n; i++)
                if (v[i] == 0) res.emplace_back(i);
            return true;
        }
    } while (next_permutation(v.begin(), v.end()));
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    need = (1 << n) - 1;
    for (int i = 0; i < n; i++) dp[i] |= (1 << i);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        int res = ((1 << u) | (1 << v));
        dp[u] |= res, dp[v] |= res;
    }
    int l = 0, r = n;
    int ans = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    int len = res.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << res[i] + 1 << (i == len - 1 ? '\n' : ' ');
    } 

    return 0;
}