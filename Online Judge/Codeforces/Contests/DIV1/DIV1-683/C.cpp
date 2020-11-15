#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 30;

int child[K * N][2];
int cnt[K * N];
int nxt = 0;

int dfs(int node) {
    if (cnt[node]) return cnt[node];
    vector<int> v;
    for (int me : {0, 1}) {
        if (child[node][me]) {
            v.emplace_back(dfs(child[node][me]));
        } else {
            v.emplace_back(0);
        }
    }
    return max(v[0] + min(1, v[1]), v[1] + min(1, v[0]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int node = 0;
        for (int bit = K - 1; bit >= 0; bit--) {
            bool me = x & (1 << bit);
            if (!child[node][me])
                child[node][me] = ++nxt;
            node = child[node][me];
        }
        cnt[node]++;
    }
    cout << n - dfs(0) << '\n';

    return 0;
}