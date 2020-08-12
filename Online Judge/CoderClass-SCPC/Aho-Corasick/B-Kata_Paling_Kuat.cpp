#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int S = 105;
const int K = 26;

struct Backtrack {
    int rest, u;
};

int n, kk, ll, len;
string s[N];
int pos[N], r[N];
vector<int> adj[N * S];
char CC[K + 5];
int val[N * S]; // value profit = P, for every vertex
int dp[N][N * S]; // (Restriction, Vertex) -> Profit
Backtrack bck[N][N * S];

struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

int add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    return v;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 


void dfs(int u) {
    for (auto v : adj[u]) {
        val[v] += val[u];
        dfs(v);
    }
}

void init() {
    len = t.size() - 1;
    for (int u = 1; u <= len; u++) {
        int v = get_link(u);
        adj[v].emplace_back(u);
    }
    dfs(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> kk >> ll;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        pos[i] = add_string(s[i]);
        cin >> val[pos[i]];
    }
    for (int i = 1; i <= kk; i++) {
        cin >> CC[i] >> r[i];
    }
    init();
    int ans = 0;
    int pos_rest = -1, pos_u = -1;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int rest = 0; rest <= ll; rest++) {
        for (int u = 0; u <= len; u++) {
            int& cur = dp[rest][u];
            if (cur == -1) continue;
            if (cur > ans) {
                ans = cur;
                pos_rest = rest, pos_u = u;
            }
            for (int i = 1; i <= kk; i++) {
                int v = go(u, CC[i]);
                if (r[i] + rest > ll) continue;
                int& nxt = dp[r[i] + rest][v];
                int curval = cur + val[v];
                if (curval > nxt) {
                    nxt = curval;
                    bck[r[i] + rest][v] = {rest, u};
                }
            }
        }
    }
    if (ans == 0) {
        cout << ans << '\n';
        return 0;
    }
    string result = "";
    while (pos_rest > 0) {
        result.push_back(t[pos_u].pch);
        auto& cur = bck[pos_rest][pos_u];
        pos_rest = cur.rest, pos_u = cur.u;
    }
    reverse(result.begin(), result.end());
    cout << ans << '\n';
    cout << result << '\n';

    return 0;
}