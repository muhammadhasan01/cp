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

    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n)), pref(n, vector<int>(n));
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            cin >> grid[i][j];
            pref[i][j] = grid[i][j] + (i > 0 ? pref[i-1][j] : 0);
        }

    int ret = INT_MIN;
    for (int a=0; a<n; a++)
        for (int b=a+2; b<n; b++) {
            int cur = 0, mx = INT_MIN, pending = INT_MIN;
            for (int j=0; j<n; j++) {
                int x = pref[b-1][j] - pref[a][j];
                cur += grid[a][j] + grid[b][j];
                if (j >= 2)
                    ret = max(ret, x + cur + mx);
                mx = max(mx, pending);
                pending = x - cur + grid[a][j] + grid[b][j];
            }
        }
    cout << ret << "\n";

    return 0;
}
