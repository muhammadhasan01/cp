#include <bits/stdc++.h>

using namespace std;

const int INF = 100001;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin >> str;
    getline(cin, str);
    int n, m, q, t;
    cin >> n >> m >> q >> t;
    vector<vector<int>> vals(q);
    vector<int> s(m);
    for (int i = 0; i < m; i++) {
        int p;
        cin >> s[i] >> p;
        --p;
        vals[p].emplace_back(s[i]);
    }
    sort(s.rbegin(), s.rend());
    int minGrade = (t > 0 ? s[t - 1] : INF);
    int k = 0;
    for (int p = 0; p < q; p++) {
        sort(vals[p].rbegin(), vals[p].rend());
        k = max(k, (int) vals[p].size());
    }
    n -= t;
    vector<int> ans(k, minGrade);
    for (int i = 0; i < k; i++) {
        vector<int> cur;
        for (int p = 0; p < q; p++) {
            if (i < (int) vals[p].size() && vals[p][i] < minGrade) {
                cur.emplace_back(vals[p][i]);
            }
        }
        sort(cur.rbegin(), cur.rend());
        int take = min(n, (int) cur.size());
        if (take > 0) {
            ans[i] = cur[take - 1];
        }
        n -= take;
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << " \n"[i == k - 1];
    }
    
    return 0;
}