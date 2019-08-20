#include<bits/stdc++.h>
using namespace std;

const int N = 105;
const int M = 1e6 + 5;
int n, m;
int dist[N][N];
vector<int> g[N];
int p[M];

void bfs(int s) {
    queue<pair<int,int>> q;
    vector<bool> vis(n + 3, 0);
    q.push({s,0});
    vis[s] = 1;
    dist[s][s] = 0;
    while(!q.empty()) {
        int u = q.front().first, h = q.front().second;
        q.pop();
        for (auto e : g[u]) {
            if (vis[e] == 0) {
                vis[e] = 1;
                dist[s][e] = h + 1;
                q.push({e,h + 1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            if (x == '1') {
                g[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    vector<int> ans;
    int pos = 0;
    for (int i = 1; i <= m; i++) {
        if (i == 1) {
            ans.push_back(p[i]);
            pos = i;
        } else {
            int tmp = ans.back();
            for (int j = i; j <= m + 1; j++) {
                if (dist[tmp][p[j]] != j - pos) {
                    ans.push_back(p[j - 1]);
                    pos = j - 1;
                    i = j - 1;
                    break;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto e : ans) cout << e << " ";

    return 0;
}
