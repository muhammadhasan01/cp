#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 2e9;

int n;
int val[N], left_p[N], right_p[N];
int deg[N];
set<int> st;

void DP(int u, int mini = -1, int maxi = INF) {
    if (mini < val[u] && val[u] < maxi) {
        st.emplace(val[u]);
    }
    if (left_p[u] != -1)
        DP(left_p[u], mini, min(maxi, val[u]));
    if (right_p[u] != -1)
        DP(right_p[u], max(mini, val[u]), maxi);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i] >> left_p[i] >> right_p[i];
        if (left_p[i] > 0) deg[left_p[i]]++;
        if (right_p[i] > 0) deg[right_p[i]]++;
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            root = i;
            break;
        }
    }
    assert(root != -1);
    int ans = 0;
    DP(root);
    for (int i = 1; i <= n; i++) {
        if (st.find(val[i]) == st.end())
            ++ans;
    }
    cout << ans << '\n';

    return 0;
}