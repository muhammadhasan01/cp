#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    vector<int> orig_l = l;
    vector<int> orig_r = r;
    vector<int> ans(n, n);
    vector<bool> mark(n);
    for (int it = 0; it < n; it++) {
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (mark[i]) {
                continue;
            }
            if (l[i] == 0 && r[i] == 0) {
                mark[i] = true;
                pos.emplace_back(i);
            }
        }
        if (pos.empty()) {
            break;
        }
        for (int i : pos) {
            for (int j = i + 1; j < n; j++) {
                if (mark[j]) {
                    continue;
                }
                ans[j]--;
                l[j] = max(0, l[j] - 1);
            }
            for (int j = i - 1; j >= 0; j--) {
                if (mark[j]) {
                    continue;
                }
                ans[j]--;
                r[j] = max(0, r[j] - 1);
            }
        }
    }
    vector<int> cl(n), cr(n);
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (ans[j] > ans[i]) {
                cl[i]++;
            }
        }
        for (int j = i + 1; j < n; j++) {
            if (ans[j] > ans[i]) {
                cr[i]++;
            }
        }
        if (cl[i] != orig_l[i] || cr[i] != orig_r[i]) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}