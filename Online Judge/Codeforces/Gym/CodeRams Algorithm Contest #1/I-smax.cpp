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

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int n, idx = 0;
bool vis[205][205];
string grid[205];
vector<array<int, 3>> pts;

int dfs(int r, int c) {
    vis[r][c] = true;
    pts.push_back({r, c, idx++});
    for (int i=0; i<4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (0 <= nr && nr < n && 0 <= nc && nc < n && grid[nr][nc] == 'x' && !vis[nr][nc])
            return 1 + dfs(nr, nc);
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> n >> k;
    int sr = -1, sc = -1;
    for (int i=0; i<n; i++) {
        cin >> grid[i];
        for (int j=0; j<n; j++)
            if (grid[i][j] == 'x')
                sr = i, sc = j;
    }

    int len = dfs(sr, sc);
    vector<vector<bool>> ban(2 * n + 1, vector<bool>(len + 1));
    for (int i=0; i<len; i++)
        for (int j=i+1; j<len; j++) {
            int d = abs(pts[i][0] - pts[j][0]) + abs(pts[i][1] - pts[j][1]), rd = abs(pts[i][2] - pts[j][2]);
            ban[d][rd] = ban[d][len - rd] = true;
        }
    for (int i=1; i<=2*n; i++)
        for (int j=0; j<=len; j++)
            if (ban[i-1][j])
                ban[i][j] = true;

    for (int d=2*n; d>0; d--) {
        int mn = 1;
        while (mn <= len && ban[d-1][mn])
            mn++;
        assert(mn <= len);
        if (len - k * mn >= 0 && !ban[d-1][len-(k-1)*mn]) {
            cout << d << "\n";
            return 0;
        }
    }
    assert(false);

    return 0;
}
