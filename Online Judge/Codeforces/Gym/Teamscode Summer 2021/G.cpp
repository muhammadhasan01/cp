#include <bits/stdc++.h>

using namespace std;

const vector<string> SIZES = {"small", "medium", "large"};

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    string cs, bev;
    cin >> cs >> bev;
    auto check = [&](const string& a, const string& b) -> bool {
        int len_a = a.size();
        int len_b = b.size();
        if (len_a != len_b) {
            return false;
        }
        int cnt = 0;
        for (int i = 0; i < len_a; i++) {
            if (a[i] != b[i]) {
                cnt += 1;
            }
        }
        return cnt == 1;
    };
    string ans_cs, ans_bev;
    for (string x : SIZES) {
        if (check(cs, x)) {
            ans_cs = x;
        }
    }
    for (string x : v) {
        if (check(bev, x)) {
            ans_bev = x;
        }
    }
    cout << ans_cs << ' ' << ans_bev << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    
    return 0;
}