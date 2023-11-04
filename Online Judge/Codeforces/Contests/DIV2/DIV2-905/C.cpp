#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> fst, lst;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!fst.count(a[i])) {
            fst[a[i]] = i;
        }
        lst[a[i]] = i;
    }
    int cnt = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (fst[a[i]] == i) {
            ++cnt;
        }
        if (lst[a[i]] == i) {
            ans += cnt;
        }
    }
    cout << ans << '\n';
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