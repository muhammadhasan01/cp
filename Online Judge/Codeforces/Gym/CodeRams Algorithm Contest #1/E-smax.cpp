#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    vector<string> grid(n);
    for (int i=0; i<n; i++)
        cin >> grid[i];

    vector<vector<long long>> tot(m);
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++)
            if (grid[i][j] == '1')
                tot[j].push_back(a[i]);
        while ((int) tot[j].size() < n)
            tot[j].emplace_back();
        sort(tot[j].rbegin(), tot[j].rend());
        DEBUG(j, tot[j])
        for (int i=1; i<n; i++)
            tot[j][i] += tot[j][i-1];
    }

    int ret = 1;
    while (ret <= n) {
        long long cur = 0;
        for (int j=0; j<m; j++)
            cur += tot[j][ret-1], DEBUG(ret, j, tot[j]);
        if (cur >= k) {
            cout << ret << "\n";
            return 0;
        }
        ret++;
    }
    cout << "-1\n";

    return 0;
}
