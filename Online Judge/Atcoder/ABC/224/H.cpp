#include <bits/stdc++.h>

using namespace std;

/** Min Cost Max Flow **/
/* complexity: O(min(E^2 V log V, E log V F)) */
/* Valid for negative cost, but not for negative cycle */
 
template<typename F, typename C>
struct MinCostMaxFlow {
    const static int MAX_NODES = 5010;
    const F kMaxFlow = 1000000000LL;
    const C kLongestCost = 1000000000LL;
    int nodes;

    MinCostMaxFlow(int _nodes = MAX_NODES, F _kMaxFlow = 1000000000, C _kLongestCost = 1000000000):
    kMaxFlow(_kMaxFlow), kLongestCost(_kLongestCost), nodes(_nodes) {}

    C prio[MAX_NODES], pot[MAX_NODES];
    F curflow[MAX_NODES];
    int prevedge[MAX_NODES], prevnode[MAX_NODES];
    bool inqueue[MAX_NODES];

    struct Edge {
        int to;
        F f, cap;
        C cost;
        int rev;
    };

    vector<Edge> graph[MAX_NODES];

    void addEdge(int s, int t, F cap, C cost) {
        Edge a = {t, 0, cap, cost, (int) graph[t].size()};
        Edge b = {s, 0, 0, -cost, (int) graph[s].size()};
        graph[s].push_back(a);
        graph[t].push_back(b);
    }

    void bellmanFord(int s, C dist[]) {
        fill(dist, dist + nodes, kLongestCost);
        dist[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            inqueue[u] = false;
            for (Edge& e: graph[u]) {
                if (e.cap <= e.f) continue;
                int v = e.to;
                C ndist = dist[u] + e.cost;
                if (dist[v] > ndist) {
                    dist[v] = ndist;
                    if (!inqueue[v]) {
                        inqueue[v] = true;
                        que.push(v);
                    }
                }
            }
        }
    }

    pair<F, C> run(int s, int t) {
        return run(s, t, kMaxFlow, kLongestCost);
    }

    pair<F, C> run(int s, int t, F maxf, C maxc) {
        // bellmanFord can be safely commented if edges costs are non-negative
        // bellmanFord(s, pot);
        F flow = 0;
        C flowCost = 0;
        while (flow < maxf) {
            fill(prio, prio + nodes, kLongestCost);
            prio[s] = 0;
            priority_queue<pair<C, int>, vector<pair<C, int>>, greater<pair<C, int>>> pq;
            pq.emplace(0, s);
            curflow[s] = kMaxFlow;
            while (!pq.empty()) {
                C d = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                if (d != prio[u]) continue;
                for (int i = 0; i < (int) graph[u].size(); i++) {
                    Edge & e = graph[u][i];
                    int v = e.to;
                    if (e.cap <= e.f) continue;
                    C nprio = prio[u] + e.cost + pot[u] - pot[v];
                    if (prio[v] > nprio) {
                        prio[v] = nprio;
                        pq.emplace(nprio, v);
                        prevnode[v] = u;
                        prevedge[v] = i;
                        curflow[v] = min(curflow[u], e.cap - e.f);
                    }
                }
            }
            if (prio[t] == kLongestCost) break;
            for (int i = 0; i < nodes; i++) pot[i] += prio[i];
            if (pot[t] >= maxc) break;
            F df = min(curflow[t], maxf - flow);
            flow += df;
            for (int v = t; v != s; v = prevnode[v]) {
                Edge & e = graph[prevnode[v]][prevedge[v]];
                e.f += df;
                graph[v][e.rev].f -= df;
                flowCost += df * e.cost;
            }
        }
        return make_pair(flow, flowCost);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int l, r;
    cin >> l >> r;
    vector<int> a(l);
    for (int i = 0; i < l; i++) {
        cin >> a[i];
    }
    vector<int> b(r);
    for (int i = 0; i < r; i++) {
        cin >> b[i];
    }
    vector<vector<int>> c(l, vector<int>(r));
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < r; j++) {
            cin >> c[i][j];
        }
    }
    int nodes = l + r + 2;
    int source = 0, sink = nodes - 1;
    MinCostMaxFlow<int, int> mcmf;
    for (int i = 0; i < l; i++) {
        mcmf.addEdge(source, i + 1, a[i], 0);
    }
    for (int i = 0; i < r; i++) {
        mcmf.addEdge(i + l + 1, sink, b[i], 0);
    }
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < r; j++) {
            mcmf.addEdge(i + 1, j + l + 1, mcmf.kMaxFlow, -c[i][j]);
        }
    }
    auto [flow, cost] = mcmf.run(source, sink);
    cout << -cost << '\n';
    
    return 0;
}