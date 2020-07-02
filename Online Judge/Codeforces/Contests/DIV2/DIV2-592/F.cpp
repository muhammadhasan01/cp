#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k;
char s[2 * N];
int par[N], sz[N];
pair<int, char> p[N];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void merge(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    if (pu != pv) {
        if (sz[pu] < sz[pv]) swap(pu, pv);
        sz[pu] += sz[pv];
        par[pv] = pu;
    }
}

char balik(char x) {
    return (x == 'B' ? 'W' : 'B');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i + n] = s[i];
    }
    for (int i = 1; i <= n; i++) {
        par[i] = i, sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (i < n && s[i] == s[i + 1]) {
            merge(i, i + 1);
        } else if (i == n && s[i] == s[1]) {
            merge(1, n);
        }
    }
    int kk = 0;
    vector<int> pos;
    for (int i = 1; i <= n; i++) {
        int szi = find(i);
        kk = max(kk, sz[szi]);
        if (sz[szi] > 1) {
            pos.push_back(i);
            pos.push_back(i + n);
            p[i] = {0, s[i]};
        }
    }
    if (kk == 1) {
        for (int i = 1; i <= n; i++) {
            cout << (k & 1 ? balik(s[i]) : s[i]);
        }
        cout << '\n';
        return 0;
    }
    sort(pos.begin(), pos.end());
    for (int i = 1; i <= n; i++) {
        int szi = sz[find(i)];
        if (szi == 1) {
            auto it = lower_bound(pos.begin(), pos.end(), i);
            int d1 = *it - i;
            auto it2 = lower_bound(pos.begin(), pos.end(), i + n);
            it2--;
            int d2 = (i + n - *it2);
            if (d1 >= d2) {
                p[i] = {d2, s[*it2]};
            } else if (d1 < d2) {
                p[i] = {d1, s[*it]};
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (k < p[i].first) {
            cout << (k & 1 ? balik(s[i]) : s[i]);
        } else {
            cout << p[i].second;
        }
    }
    cout << '\n';

    return 0;
}
