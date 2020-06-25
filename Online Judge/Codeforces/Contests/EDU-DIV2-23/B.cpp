#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N], b[N];
int pre[N][4], suf[N][4];

int upp(int x) {
    if (++x == 4) x = 1;
    return x;
}

int down(int x) {
    if (--x == 0) x = 3;
    return x;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            pre[i][j] = pre[i - 1][j] + (a[i] == b[j]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= 3; j++) {
            suf[i][j] = suf[i + 1][j] + (a[i] == b[j]);
        }
    }
    unordered_map<int, int> ord;
    vector<int> v;
    for (int i = 1; i <= 3; i++) {
        ord[b[i]] = i;
        v.emplace_back(b[i]);
    }
    vector<vector<int>> w;
    map<vector<int>, bool> mp;
    do {
        if (mp[v]) continue;
        mp[v] = 1;
        w.emplace_back(v);
    } while (next_permutation(v.begin(), v.end()));
    long long ans = 0;
    for (int i = 2; i <= n - 1; i++) {
        for (auto& e : w) {
            if (e[1] != a[i]) continue;
            ans += (1LL) * pre[i - 1][ord[e[0]]] * suf[i + 1][ord[e[2]]];
        }
    }
    cout << ans << '\n';

    return 0;
}