#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
long long w;
pair<int, int> a[N];

void solve() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n, greater<pair<int, int>>());
    long long dw = (w + 1) / 2;
    long long res = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if ((long long) a[i].first > w) continue;
        v.emplace_back(a[i].second);
        res += a[i].first;
        if (dw <= res && res <= w) {
            int len = v.size();
            cout << len << '\n';
            for (int i = 0; i < len; i++) {
                cout << v[i] << (i == len - 1 ? '\n' : ' ');
            }
            return;
        }
    }
    cout << -1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}