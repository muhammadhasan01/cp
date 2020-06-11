#include <bits/stdc++.h>

using namespace std;

const int K = 300;
const int M = K * K + 5;

int n;
vector<int> g[M];
int node[K][K];
int indeg[M], outdeg[M];
pair<int, int> idx[M];

void dismiss() {
    cout << "NO" << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int id = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            node[i][j] = ++id;
            idx[id] = make_pair(i, j);
        }
    }
    cin >> n;
    int cur_node;
    for (int i = 1; i <= n; i++) {
        char x, y, z;
        cin >> x >> y >> z;
        int u = node[int(x)][int(y)];
        int v = node[int(y)][int(z)];
        cur_node = u;
        g[u].emplace_back(v);
        outdeg[u]++;
        indeg[v]++;
    }
    int cnt = 0;
    for (int i = 1; i < M; i++) {
        int dif = outdeg[i] - indeg[i];
        if (abs(dif) & 1) {
            ++cnt;
            if (outdeg[i] >= indeg[i]) cur_node = i;
        } else if (dif != 0) {
            dismiss();
        }
    }
    if (cnt != 2 && cnt != 0) dismiss();
    deque<int> eul_path;
    stack<int> cur_path;
    cur_path.emplace(cur_node);
    while (!cur_path.empty()) {
        if (!g[cur_node].empty()) {
            cur_path.emplace(cur_node);
            int nxt_node = g[cur_node].back();
            g[cur_node].pop_back();
            cur_node = nxt_node;
        } else {
            eul_path.emplace_front(cur_node);
            cur_node = cur_path.top();
            cur_path.pop();
        }
    }
    int len = eul_path.size();
    if (len != n + 1) dismiss();
    cout << "YES" << '\n';
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            cout << char(idx[eul_path[i]].first) << char(idx[eul_path[i]].second);
        } else {
            cout << char(idx[eul_path[i]].second);
        }
    }
    cout << '\n';

    return 0;
}