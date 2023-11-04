#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, C;
    cin >> n >> C;
    vector<long long> big(C + 1);
    set<int> cc;
    for (int i = 0; i < n; i++) {
        int c;
        long long d, h;
        cin >> c >> d >> h;
        big[c] = max(big[c], d * h);
        cc.emplace(c);
    }
    for (int i : cc) {
        long long cur = 0;
        for (int j = i; j <= C; j += i) {
            cur += big[i];
            big[j] = max(big[j], cur);
        }
    }
    for (int i = 1; i <= C; i++) {
        big[i] = max(big[i], big[i - 1]);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        long long D, H;
        cin >> D >> H;
        long long val = D * H;
        int ans = upper_bound(big.begin(), big.end(), val) - big.begin();
        if (ans > C) {
            ans = -1;
        }
        cout << ans << " \n"[i == m - 1];
    }
    
    return 0;
}