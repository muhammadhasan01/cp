#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    long long val = sum / n;
    long long have = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= val) {
            have += a[i] - val;
        } else if (a[i] < val) {
            long long dif = val - a[i];
            if (dif > have) {
                cout << "NO" << '\n';
                return;
            }
            have -= dif;
        }
    }
    cout << "YES" << '\n';
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