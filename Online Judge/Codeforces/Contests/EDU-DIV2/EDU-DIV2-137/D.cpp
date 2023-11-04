#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int K = 30;

bitset<N> s;
bitset<N> p;

void solve() {
    int n;
    cin >> n;
    vector<int> pos;
    for (int i = n - 1; i >= 0; i--) {
        char cc;
        cin >> cc;
        if (cc == '1') {
            s[i] = p[i] = 1;
        } else if (cc == '0') {
            s[i] = p[i] = 0;
        }
    }
    string ans = s.to_string();
    for (int it = 0; it < min(n, K); it++) {
        string cur = (s | p).to_string();
        ans = max(ans, cur);
        p >>= 1;
    }
    int at = ans.find_first_not_of('0');
    if (at == -1) {
        cout << 0 << '\n';
        return;
    }
    for (int i = at; i < (int) ans.size(); i++) {
        cout << ans[i];
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}