#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(K);
    stack<pair<char, int>> st;
    for (char cc : s) {
        if (st.empty() || st.top().first != cc) {
            st.emplace(cc, 1);;
            continue;
        }
        auto [_, c] = st.top();
        st.pop();
        st.emplace(cc, c + 1);
    }
    while (!st.empty()) {
        auto [cc, c] = st.top();
        st.pop();
        int num = cc - 'a';
        cnt[num] = max(cnt[num], c);
    }
    long long ans = 0;
    for (int i = 0; i < K; i++) {
        ans += cnt[i];
    }
    cout << ans << '\n';
    
    return 0;
}