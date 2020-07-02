#include <bits/stdc++.h>

using namespace std;

const int N = 200;
const int INF = 999999998;

int tc;
int n, k;
int ans[30][N];

int eval(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

void check(int x, int k) {
    int ret = 0;
    int m = x;
    for (int i = 0; i <= k; i++) {
        ret += eval(x);
        ++x;
    }
    if (ret > N) return;
    if (ans[k][ret] == -1) ans[k][ret] = m;
}

void solve() {
    cin >> n >> k;
    if (k == 0) {
        if (n <= 9) {
            cout << n << '\n';
        } else {
            vector<int> v;
            while (n > 0) {
                v.emplace_back(min(n, 9));
                n -= 9;
            }
            reverse(v.begin(), v.end());
            for (auto& e : v) cout << e;
            cout << '\n';
        }
    } else {
        cout << ans[k][n] << '\n';
    }
}

void getz(deque<int> v) {
    int len = v.size();
    if (len == 9) return;
    for (int i = 1; i <= 9; i++) {
        int res = i;
        for (int i = 0; i < len; i++) {
            res = res * 10 + v[i];
        }
        check(res, 1);
    }
    v.emplace_front(9);
    getz(v);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(ans, -1, sizeof(ans));
    for (int i = 0; i <= 100000; i++) {
        check(i, 1);
    }
    getz({8, 9});
    getz({9, 8});
    for (int i = 0; i <= 800000; i++) {
        for (int k = 2; k <= 9; k++) {
            check(i, k);
        }
    }
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}