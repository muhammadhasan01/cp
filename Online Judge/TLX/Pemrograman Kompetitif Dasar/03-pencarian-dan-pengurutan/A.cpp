#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    long long x;
    cin >> n >> x;
    pair<long long, long long> res = make_pair(INF, -1);
    for (int i = 0; i < n; i++) {
        long long y;
        cin >> y;
        res = min(res, make_pair(abs(x - y), y));
    }
    cout << res.second << '\n';

    return 0;
}