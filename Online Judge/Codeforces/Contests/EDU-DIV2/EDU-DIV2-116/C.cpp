#include <bits/stdc++.h>

using namespace std;

const int K = 18;

long long ten[K];

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    k += 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string res = "";
    long long cur = 0;
    for (int i = 0; i < n - 1; i++) {
        int dif = a[i + 1] - a[i];
        long long mx = min(k - cur, ten[dif] - 1);
        cur += mx;
        string str = to_string(mx);
        res = str + res;
        if (cur == k) {
            break;
        }
    }
    if (cur < k) {
        string str = to_string(k - cur);
        res = str + res;
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ten[0] = 1;
    for (int i = 1; i < K; i++) {
        ten[i] = ten[i - 1] * 10;
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}