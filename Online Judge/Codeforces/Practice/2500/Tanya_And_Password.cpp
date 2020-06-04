#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int A = 30;
const int N = 2e5 + 5;
const int INF = 2e9;

struct st {
    int x, y, z;
};

int n;
st a[N];
int c[A][A];
set<int> st[A][A];
int dp[N], go[N];

int DP(int u) {
    cerr << u << " => " << dp[u] << '\n';
    if (dp[u] != 0) return dp[u];
    st[a[u].x][a[u].y].erase(u);
    int res = 1;
    for (auto v : st[a[u].y][a[u].z]) {
        cerr << u << " jeung " << v << '\n';
        int cur = 1 + DP(v);
        if (cur > res) {
            res = cur;
            go[u] = v;
        }
    }
    st[a[u].x][a[u].y].emplace(u);
    return dp[u] = res;
}

void dismiss() {
    cout << "NO" << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a[i].x = s[0] - 'a';
        a[i].y = s[1] - 'a';
        a[i].z = s[2] - 'a';
        st[a[i].x][a[i].y].emplace(i);
        c[a[i].y][a[i].z]++;
    }
    int mini = INF, pos = -1;
    for (int i = 1; i <= n; i++) {
        if (c[a[i].x][a[i].y] < mini) {
            mini = c[a[i].x][a[i].y];
            pos = i;
        }
    }
    cerr << pos << '\n';
    DP(pos);
    cerr << dp[pos] << '\n';
    if (dp[pos] < n) dismiss();
    cerr << "hasilnya adalah " << '\n';
    cerr << dp[pos] << '\n';
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        cerr << i << " => " << pos << '\n';
        ans.push_back(pos);
        pos = go[pos];
    }
    return 0;
}