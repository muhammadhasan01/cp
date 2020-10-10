#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/** END OF TEMPLATE DEBUGGER **/

const int N = 1e3 + 5;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct item {
    int cnt, dir;
    int x, y;
    item(int c, int d, int x, int y) : cnt(c), dir(d), x(x), y(y) { }
};

int n, m;
char a[N][N];
bool vis[3][N][N];
int sx, sy, tx, ty;

void BFS(int dir) {
    queue<item> q;
    q.emplace(2, dir, sx, sy);
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            if (cur.dir != i && cur.cnt == 0) continue;
            int cx = cur.x + dx[i];
            int cy = cur.y + dy[i];
            if (cx < 1 || cx > n || cy < 1 || cy > m) continue;
            if (a[cx][cy] == '*') continue;
            int rescnt = (cur.dir == i ? cur.cnt : cur.cnt - 1);
            if (vis[rescnt][cx][cy]) continue;
            vis[rescnt][cx][cy] = 1;
            if (cx == tx && cy == ty) {
                cout << "YES" << "\n";
                exit(0); 
            }
            q.emplace(rescnt, i, cx, cy);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                sx = i, sy = j;
            } else if (a[i][j] == 'T') {
                tx = i, ty = j;
            }
        }
    }
    for (int dir = 0; dir < 4; dir++) {
        BFS(dir);
    }
    cout << "NO" << '\n';

    return 0;
}