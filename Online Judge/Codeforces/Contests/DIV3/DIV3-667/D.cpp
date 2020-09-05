#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int tc;
long long n;
int s;
vector<long long> v;

int F(long long x) {
    int ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

void solve() {
    cin >> n >> s;
    if (F(n) <= s) {
        cout << 0 << '\n';
        return;
    }
    long long m = *lower_bound(v.begin(), v.end(), n);
    long long ans = m - n;
    string res = to_string(n);
    int len = res.size();
    int ret = 0;
    for (int i = 0; i < len - 1; i++) {
        ret += (res[i] - '0');
        if (res[i] == '9') continue;
        if (ret + 1 > s) continue;
        string cur = res;
        cur[i] = res[i] + 1;
        for (int j = i + 1; j < len; j++)
            cur[j] = '0';
        long long curval = stoll(cur);
        ans = min(ans, curval - n);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long cur = 1;
    while (1) {
        v.emplace_back(cur);
        if (cur == INF) break;
        cur *= 10LL;
    }
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}