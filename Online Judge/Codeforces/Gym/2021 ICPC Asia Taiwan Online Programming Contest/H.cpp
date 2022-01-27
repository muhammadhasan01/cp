#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;

namespace atcoder {
 
template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}
 
    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }
 
    struct edge {
        int from, to;
        Cap cap, flow;
    };
 
    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }
 
    Cap flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
 
        std::vector<int> level(_n), iter(_n);
        std::queue<int> que;
 
        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            while (!que.empty()) que.pop();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };
 
        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }
 
    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        std::queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
 
  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};
 
}

const int B = 16;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
    }
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    int q;
    cin >> q;
    vector<tuple<int, int, int, int, int>> r(q);
    for (auto& [t, u, x, v, y] : r) {
        cin >> t >> u >> x >> v >> y;
    }
    map<pair<int, int>, int> mp;
    for (auto& [t, u, x, v, y] : r) {
        pair<int, int> ux = make_pair(u, x);
        pair<int, int> vy = make_pair(v, y);
        if (!mp.count(ux)) {
            mp[ux] = (int) mp.size();
        }
        if (!mp.count(vy)) {
            mp[vy] = (int) mp.size();
        }
    }
    int ans = INF;
    int len = (int) mp.size();
    for (int b = 0; b < (1 << len); b++) {
        bool flag = true;
        for (auto& [t, u, x, v, y] : r) {
            pair<int, int> ux = make_pair(u, x);
            pair<int, int> vy = make_pair(v, y);
            int b1 = bool(b & (1 << mp[ux]));
            int b2 = bool(b & (1 << mp[vy]));
            if ((b1 ^ b2) ^ t) {
                flag = false;
                break;
            }
            if (a[u] != -1) {
                if ((a[u] >> x) & 1 != b1) {
                    flag = false;
                    break;
                }
            }
            if (a[v] != -1) {
                if ((a[v] >> y) & 1 != b2) {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag) {
            continue;
        }
        int nodes = B * n + 2;
        int source = nodes - 2;
        int sink = nodes - 1;
        atcoder::mf_graph<int> dinic(nodes);
        for (auto& [p, w] : mp) {
            int node = p.first * B + p.second;
            if ((b >> w) & 1) {
                dinic.add_edge(node, sink, INF);
            } else {
                dinic.add_edge(source, node, INF);
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                continue;
            }
            for (int j = 0; j < B; j++) {
                int node = i * B + j;
                if ((a[i] >> j) & 1) {
                    dinic.add_edge(node, sink, INF);
                } else {
                    dinic.add_edge(source, node, INF);
                }
            }
        }
        for (auto& [u, v] : edges) {
            for (int j = 0; j < B; j++) {
                int U = u * B + j;
                int V = v * B + j;
                dinic.add_edge(U, V, 1);
                dinic.add_edge(V, U, 1);
            }
        }
        ans = min(ans, dinic.flow(source, sink));
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';
    
    return 0;
}