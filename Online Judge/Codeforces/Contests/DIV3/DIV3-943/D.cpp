#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto getAns = [&](int pos) -> long long {
        long long mx = a[pos];
        int cur = p[pos];
        while (cur != pos) {
            mx = max(mx, a[cur]);
            cur = p[cur];
        }
        long long ret = 1LL * k * a[pos];
        long long sum = a[pos];
        int at = p[pos];
        for (int i = 1; i < k; i++) {
            long long val = sum + a[at] * 1LL * (k - i);
            ret = max(ret, val);
            if (a[at] == mx) {
                break;
            }
            sum += a[at];
            at = p[at];
        }
        return ret;
    };

    long long B = getAns(pb);
    long long S = getAns(ps);
    if (B > S) {
        cout << "Bodya" << '\n'; 
    } else if (B < S) {
        cout << "Sasha" << '\n';
    } else {
        cout << "Draw" << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}