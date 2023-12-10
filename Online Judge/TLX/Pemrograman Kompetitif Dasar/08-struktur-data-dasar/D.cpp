#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<int> st;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        ans += st.empty() ? i + 1 : i - st.top();
        st.emplace(i);
    }
    cout << ans << '\n';
    
    return 0;
}