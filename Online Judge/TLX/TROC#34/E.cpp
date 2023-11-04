#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int sp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 2; i < N; i++) {
        if (sp[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            sp[j] = i;
        }
    }
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> vis(N);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vis[a[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        if (a[n - 1] % a[i] != 0) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for (int i = 0; i + 1 < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int lcm = a[i] * (a[j] / __gcd(a[i], a[j]));
            if (!vis[lcm]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    vector<int> highest(N);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ans.emplace_back(a[i]);
            continue;
        }
        vector<pair<int, int>> P;
        int x = a[i];
        while (x > 1) {
            int pp = sp[x];
            int cnt = 0;
            while (x % pp == 0) {
                x /= pp;
                ++cnt;
            }
            P.emplace_back(pp, cnt);
        }
        bool take = false;
        for (auto [p, c] : P) {
            if (highest[p] < c) {
                highest[p] = c;
                take = true;
            }
        }
        if (take) {
            ans.emplace_back(a[i]);
        }
    }
    if (ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    int len = (int) ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
    
    return 0;
}