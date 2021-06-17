#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 2000 + 5;

int n, k;
int dis[N], par[N];

int main() {
    for (int i = 0; i < N; i++) {
        dis[i] = INF;
    }
    cin >> n >> k;
    queue<int> q;
    dis[0] = 0;
    par[0] = -1;
    q.emplace(0);
    while (!q.empty()) {
        int c = q.front(); q.pop(); // c -> num selected
        for (int i = 0; i <= k; i++) { // num unselected we add
            if (i <= n - c && k - i <= c) {
                int to = c + i - (k - i);
                if (dis[to] == INF) {
                    dis[to] = dis[c] + 1;
                    par[to] = c;
                    q.emplace(to);
                }
            }
        }
    }
    if (dis[n] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> sel, nosel(n);
    iota(nosel.begin(), nosel.end(), 1);
    reverse(nosel.begin(), nosel.end());
    // get ans
    vector<int> path;
    for (int c = n; c != -1; c = par[c])
        path.push_back(c);
    reverse(path.begin(), path.end());
    int sz = path.size(), ans = 0;
    for (int i = 0; i < sz - 1; i++) {
        // a - (k - a) = d
        // a - k + a = d
        // 2a - k = d
        // 2a = d + k
        // a = (d + k) / 2
        int a = path[i], b = path[i + 1], d = b - a;
        int nsel = (d + k) / 2, nnosel = k - nsel;
        assert((d + k) % 2 == 0);
        vector<int> cnosel, csel;
        for (auto j = 0; j < nsel; j++) {
            csel.emplace_back(nosel.back());
            nosel.pop_back();
        }
        for (auto j = 0; j < nnosel; j++) {
            cnosel.emplace_back(sel.back());
            sel.pop_back();
        }
        // make query
        cout << "? ";
        for (auto x : csel) cout << x << ' ';
        for (auto x : cnosel) cout << x << ' ';
        cout << '\n'; cout.flush();
        // update nosel, sel
        nosel.insert(nosel.end(), cnosel.begin(), cnosel.end());
        sel.insert(sel.end(), csel.begin(), csel.end());
        int res; cin >> res;
        ans ^= res;
    }
    assert(nosel.empty());

    cout << "! " << ans << '\n';
    cout.flush();
}