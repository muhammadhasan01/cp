#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int rep = 0; rep < n - 1; rep++) {
        sort(a.begin(), a.end());
        vector<int> res;
        res.emplace_back((a[0] + a[1]) / 2);
        for (int i = 2; i < (int) a.size(); i++) {
            res.emplace_back(a[i]);
        }
        a = res;
    }
    cout << a[0] << '\n';
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