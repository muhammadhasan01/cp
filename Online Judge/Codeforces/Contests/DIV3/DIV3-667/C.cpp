#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int tc;

vector<int> gen(int x, int y, int n) {
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        ret[i] = x + y * i;
    }
    return ret;
}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ret(n, INF);
    int res = y - x;
    for (int dif = 1; dif <= 50; dif++) {
        if (res % dif != 0) continue;
        int cur = res / dif;
        for (int j = 2; j <= n; j++) {
            int i = j - cur;
            if (i < 1) continue;
            int firstEl = x - (i - 1) * dif;
            if (firstEl <= 0) continue;
            vector<int> cur_res = gen(firstEl, dif, n);
            if (cur_res[n - 1] < ret[n - 1])
                ret = cur_res;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}