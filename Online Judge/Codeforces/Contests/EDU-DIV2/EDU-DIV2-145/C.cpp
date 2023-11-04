#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, -MAX);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (sum == k) {
            break;
        }
        if (sum + i <= k) {
            sum += i;
            a[i] = 30;
        } else {
            int dif = k - sum;
            a[i] = 30 * (dif - i) + 1;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}