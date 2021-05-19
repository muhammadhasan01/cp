#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, m;
unordered_map<int, char> in[N], out[N];
multiset<pair<char, char>> ms[N];
int odd = 0, even = 0, dob = 0;

void add(int u, int v) {
    char x = in[u][v];
    char y = out[u][v];
    if (x == y)
        odd++;
    else if (ms[u].find(make_pair(y, x)) != ms[u].end())
        even++;
    ms[u].emplace(x, y);
    ++dob;
}

void del(int u, int v) {
    char x = in[u][v];
    char y = out[u][v];
    if (x == y) {
        odd -= 2;
    } else {
        if (ms[u].find(make_pair(y, x)) != ms[u].end())
            even--;
        if (ms[v].find(make_pair(x, y)) != ms[v].end())
            even--;
    }
    auto it_u = ms[u].find(make_pair(x, y));
    if (it_u != ms[u].end()) {
        ms[u].erase(it_u);
        --dob;
    }
    auto it_v = ms[v].find(make_pair(y, x));
    if (it_v != ms[v].end()) {
        ms[v].erase(it_v);
        --dob;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while (m--) {
        char tp;
        cin >> tp;
        if (tp == '+') {
            int u, v; char c;
            cin >> u >> v >> c;
            in[v][u] = out[u][v] = c;
            if (in[u].count(v)) {
                add(v, u);
            }
            if (out[v].count(u)) {
                add(u, v);
            }
        } else if (tp == '-') {
            int u, v;
            cin >> u >> v;
            if (in[u].count(v)) {
                del(u, v);
            }
            in[v].erase(u);
            out[u].erase(v);
        } else if (tp == '?') {
            int k;
            cin >> k;
            bool ok = false;
            if (odd)
                ok = true;
            if (dob && (k % 2 == 1))
                ok = true;
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}