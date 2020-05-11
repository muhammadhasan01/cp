#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int tc;
int n, m;
vector<vector<char>> c, s;
vector<int> par, sz, vis, dist, post;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int getIdx(int x, int y) {
    return (x - 1) * m + y;
}

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    par[pv] = pu;
}

void dfs(int x, int y) {
    int cx = x, cy = y;
    if (s[x][y] == 'L') {
        cy--;
    } else if (s[x][y] == 'R') {
        cy++;
    } else if (s[x][y] == 'U') {
        cx--;
    } else if (s[x][y] == 'D') {
        cx++;
    }
    int curIdx = getIdx(cx, cy);
    int nowIdx = getIdx(x, y);
    merge(nowIdx, curIdx);
    if (vis[curIdx]) return;
    vis[curIdx] = 1;
    dfs(cx, cy);
}

int DFS(int x, int y, int lastz) {
    int curIdx = getIdx(x, y);
    if (vis[curIdx]) {
        return dist[curIdx];
    }
    vis[curIdx] = 1;
    if (curIdx == lastz) {
        return dist[curIdx] = 0;
    }
    if (s[x][y] == 'L') {
        return dist[curIdx] = 1 + DFS(x, y - 1, lastz);
    } else if (s[x][y] == 'R') {
        return dist[curIdx] = 1 + DFS(x, y + 1, lastz);
    } else if (s[x][y] == 'U') {
        return dist[curIdx] = 1 + DFS(x - 1, y, lastz);
    } else if (s[x][y] == 'D') {
        return dist[curIdx] = 1 + DFS(x + 1, y, lastz);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        par.assign(n * m + 1, 0);
        sz.assign(n * m + 1, 0);
        vis.assign(n * m + 1, 0);
        dist.assign(n * m + 1, 0);
        post.assign(n * m + 1, 0);
        c.assign(n + 1, vector<char>(m + 1));
        s.assign(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c[i][j];
                int curIdx = getIdx(i, j);
                par[curIdx] = curIdx;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> s[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int curIdx = getIdx(i, j);
                if (!vis[curIdx]) {
                    vis[curIdx] = 1;
                    dfs(i, j);
                }
            }
        }
        int ansMax = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int curIdx = getIdx(i, j);
                if (curIdx != par[curIdx]) continue;
                int sizeCycle = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[curIdx] = 0;
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    int cx = x, cy = y;
                    if (s[x][y] == 'L') {
                        cy--;
                    } else if (s[x][y] == 'R') {
                        cy++;
                    } else if (s[x][y] == 'U') {
                        cx--;
                    } else if (s[x][y] == 'D') {
                        cx++;
                    }
                    int idx_1 = getIdx(x, y);
                    int idx_2 = getIdx(cx, cy);
                    if (vis[idx_2]) {
                        vis[idx_2] = 0;
                        dist[idx_2] = dist[idx_1] + 1;
                        q.push({cx, cy});
                    } else {
                        sizeCycle = dist[idx_1] - dist[idx_2] + 1;
                        sz[curIdx] = sizeCycle;
                        post[curIdx] = idx_1;
                        break;
                    }
                }
                ansMax += sizeCycle;
            }
        }
        fill(vis.begin(), vis.end(), 0);
        fill(dist.begin(), dist.end(), 0);
        set<pair<int, int>> st;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int curIdx = getIdx(i, j);
                int parent = fpar(curIdx);
                int lastz = post[parent];
                int curDist = DFS(i, j, lastz);
                if (c[i][j] == '0') {
                    int sizeCycle = sz[parent];
                    st.insert({lastz, curDist % sizeCycle});
                }
            }
        }
        int ansBlack = st.size();
        cout << ansMax << " " << ansBlack << '\n';
    }

    return 0;
}