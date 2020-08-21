#include <bits/stdc++.h>

using namespace std;

const int N = 4e2 + 5;

int n;
map<string, int> mp;
vector<int> adj[N];
int id[N];
int hit[N];
bool vis[N];

bool isProgram(const string& str) {
    string programName = "";
    int cnt = 0;
    for (char CC : str) {
        if (cnt == 2) programName += CC;
        if (CC == ':') ++cnt;
    }
    return (programName == "PROGRAM");
}

void dfs(int u) {
    ++hit[u];
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int cnt = 0; queue<int> q;
    for (int i = 1; i <= n; i++) {
        string str; cin >> str;
        if (!mp.count(str)) {
            mp[str] = ++cnt;
        }
        id[i] = mp[str];
        if (isProgram(str)) {
            q.emplace(id[i]);
        }
        int k; cin >> k;
        for (int j = 1; j <= k; j++) {
            string dir; cin >> dir;
            if (!mp.count(dir)) {
                mp[dir] = ++cnt;
            }
            adj[mp[dir]].emplace_back(id[i]);
        }
    }
    while (!q.empty()) {
        fill(vis + 1, vis + 1 + n, 0);
        int u = q.front(); q.pop();
        dfs(u);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (hit[i] == 0)
            ++res;
    }
    cout << res << '\n';

    return 0;
}