#include <bits/stdc++.h>

using namespace std;

const int K = 26;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s.back()) {
        cout << "NO" << '\n';
        return;
    }

    vector<int> cnt(K);
    for (char cc : s) {
        cnt[(int) (cc - 'a')]++;
    }
    int odd = 0;
    for (int i = 0; i < K; i++) {
        if (cnt[i] & 1) {
            odd++;
        }
    }
    if (odd > 1) {
        cout << "NO" << '\n';
        return;
    }
    set<int> st;
    for (int i = 0; i < K; i++) {
        if (cnt[i] & 1) {
            cnt[i]--;
        }
        if (cnt[i] > 0) {
            st.emplace(i);
        }
    }
    int len = (int) st.size();
    cout << (len == 1 ? "NO" : "YES") << '\n';
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