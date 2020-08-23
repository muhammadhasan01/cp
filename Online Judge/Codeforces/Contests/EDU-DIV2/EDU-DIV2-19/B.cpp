#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e16;

int n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> val;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (abs(x) % 2 == 0) {
            if (x > 0) res += x;
        } else {
            val.emplace_back(x);
        }
    }
    sort(val.begin(), val.end(), greater<int>());
    int len = val.size();
    assert(len > 0);
    long long ans = -INF, sum = res;
    for (int i = 0; i < len; i++) {
        sum += val[i];
        if (i % 2 == 0) {
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';

    return 0;
}