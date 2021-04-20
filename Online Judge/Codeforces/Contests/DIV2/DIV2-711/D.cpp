#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1e5 + 5;
const long long C = 1e5;

struct st {
    int t, y;
    long long x;
};

int n, m;
st p[N];
int ans[N];
int available[N];
queue<int> pre[N];

long long ceil(long long x, long long y) {
    return (x + y - 1) / y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].t >> p[i].x >> p[i].y;
    }
    for (int i = 1; i <= m; i++) {
        ans[i] = INF;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i].t == 1) {
            long long add = ceil(p[i].x, C);
            if (add == 0) continue;
            for (int j = 0; j <= m; j++) {
                int rem = j % add;
                if (ans[j] == INF) {
                    if (available[rem]) {
                        ans[j] = i;
                    }
                } else {
                    int next = min(1LL * m, add * p[i].y + j);
                    available[rem]++;
                    pre[next].emplace(rem);
                }
                while (!pre[j].empty()) {
                    int cur = pre[j].front();
                    pre[j].pop();
                    available[cur]--;
                }
            }
        } else if (p[i].t == 2) {
            for (int j = 1; j <= m; j++) {
                if (ans[j] >= i) continue;
                long long cur = j;
                for (int rep = 0; rep < p[i].y; rep++) {
                    long long bfr = cur;
                    cur = ceil(1LL * cur * p[i].x, C);
                    if (cur < 1 || cur > m || ans[cur] < i) break;
                    ans[cur] = i;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (ans[i] == INF) ans[i] = -1;
        cout << ans[i] << " \n"[i == m];
    }

    return 0;
}