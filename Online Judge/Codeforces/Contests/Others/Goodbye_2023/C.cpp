#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int pre[N];

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    int cnt = 0;
    vector<long long> ans(n);
    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            ++cnt;
        }
        sum += a[i];
        if (i == 0) {
            ans[i] = sum;
        } else {
            ans[i] = sum - pre[cnt];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    pre[1] = 1;
    pre[2] = 0;
    pre[3] = 1;
    pre[4] = 2;
    pre[5] = 1;
    for (int i = 6; i < N; i++) {
        pre[i] = pre[i - 3] + 1;
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}