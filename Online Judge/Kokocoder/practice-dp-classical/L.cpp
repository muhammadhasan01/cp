#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 100;
const int V = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, maxWeight;
    cin >> n >> maxWeight;
    vector<int> dp(V, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        for (int j = V - 1; j >= 0; j--) {
            int k = j + v;
            if (k < V) {
                dp[k] = min(dp[k], dp[j] + w);
            }
        }
    }
    for (int v = V - 1; v >= 0; v--) {
        if (dp[v] <= maxWeight) {
            cout << v << '\n';
            return 0;
        }
    }

    return 0;
}