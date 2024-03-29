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
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++) {
        cin >> b[i];
        if (i > 0) b[i] -= b[0];
    }
    b[0] = 0;

    map<int, int> mp;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            mp[a[i] - b[j]]++;
            mp[a[i] - b[j] + 1]--;
        }

    int ret = 0, cur = 0;
    for (auto &p : mp) {
        cur += p.second;
        ret = max(ret, cur);
    }
    cout << ret << "\n";

    return 0;
}
