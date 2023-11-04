#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    stack<int> st;
    priority_queue<int> pq;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.emplace(i);
        } else {
            int j = st.top();
            st.pop();
            int len = i - j - 1;
            ans += len / 2;
            pq.emplace(len);
        }
    }
    while (!pq.empty() && k > 0) {
        ans -= pq.top() / 2;
        pq.pop();
        --k;
    }
    cout << ans << '\n';
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