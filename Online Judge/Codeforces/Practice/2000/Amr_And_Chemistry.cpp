#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;
int n;
int cnt[N], vis[N], stp[N];
int ans = inf;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        queue<pair<int, int>> q;
        q.push({x, 0});
        while (!q.empty()) {
            int p1 = q.front().first;
            int p2 = q.front().second;
            q.pop();
            if (p1 >= N) continue;
            if (vis[p1] == i) continue;
            vis[p1] = i;
            stp[p1] += p2;
            cnt[p1]++;
            q.push({p1 * 2, p2 + 1});
            q.push({p1 / 2, p2 + 1});
        }
    }
    for (int i = 0; i < N; i++) {
        if (cnt[i] == n) {
            ans = min(ans, stp[i]);
        }
    }
    cout << ans << '\n';

    return 0;
}
