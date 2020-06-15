#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        st.emplace(x);
    }
    int len = st.size();
    if (len == 1) {
        cout << 1 << '\n';
    } else if (len < n) {
        cout << n - 1 << '\n';
    } else if (len == n) {
        cout << n << '\n';
    }

    return 0;
}