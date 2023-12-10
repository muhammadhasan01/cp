#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bitset<N> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dp |= (dp << x);
    }
    vector<int> res;
    for (int x = 1; x < N; x++) {
        if (dp[x]) {
            res.emplace_back(x);
        }
    }
    int len = (int) res.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << res[i] << " \n"[i == len - 1];
    }
    
    return 0;
}