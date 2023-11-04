#include <bits/stdc++.h>

using namespace std;

const int K = 15;

void solve() {
    string s;
    cin >> s;
    vector<int> pos(K);
    int n = s.length();
    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        pos[x] = i;
    }
    if (pos[1] < pos[3]) {
        cout << 13 << '\n';
    } else {
        cout << 31 << '\n';
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