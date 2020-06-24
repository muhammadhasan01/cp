#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;

int n;
int ans;
int curcnt;
long long b;
long long c[N], d[N];
long long curval;
set<pair<int, int>> rem;
vector<int> g[N];

void check() {
    int cur = curcnt;
    long long val = curval;
    cerr << '\n';
    for (auto& e : rem) {
        val += e.first;
        if (val > b) break;
        cerr << e.first << " dan " << e.second << '\n';
        ++cur;
    }
    cerr << cur << " => " << val << '\n';
    ans = max(ans, cur);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
        rem.emplace(c[i], i);
        if (i > 1) {
            int x;
            cin >> x;
            g[x].emplace_back(i);
        }
    }
    set<pair<int, int>> st;
    st.emplace(c[1] - d[1], 1);
    while (!st.empty()) {
        auto it = st.begin();
        long long val = it->first;
        int u = it->second;
        st.erase(it);
        check();
        rem.erase(make_pair(c[u], u));
        ++curcnt;
        curval += val;
        if (curval > b) break;
        for (auto v : g[u]) {
            st.emplace(c[v] - d[v], v);
        }
    }
    if (curval <= b) check();
    cout << ans << '\n';

    return 0;
}