#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> L(n);
    {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }
            L[i] = st.empty() ? -1 : st.top();
            st.emplace(i);
        }    
    }
    vector<int> R(n);
    {
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] >= a[i]) {
                st.pop();
            }
            R[i] = st.empty() ? n : st.top();
            st.emplace(i);
        }
    }
    vector<int> dp(n + 2);
    for (int i = 0; i < n; i++) {
        int len = R[i] - L[i] - 1;
        dp[len] = max(dp[len], a[i]);
    }
    for (int i = n; i >= 1; i--) {
        dp[i] = max(dp[i], dp[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}