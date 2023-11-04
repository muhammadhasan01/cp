#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto getDivs = [&](int x) -> vector<int> {
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            ret[i] = x - a[i] % x;
            if (ret[i] == x) {
                ret[i] = 0;
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    };

    if (k != 4) {
        vector<int> div = getDivs(k);
        cout << div[0] << '\n';
        return;
    }
    vector<int> div4 = getDivs(4);
    vector<int> div2 = getDivs(2);
    cout << min(div4[0], div2[0] + div2[1]) << '\n';
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