#include <bits/stdc++.h>

using namespace std;

int tc;

void solve() {
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.emplace(x);
    }
    cout << ((int) st.size() == 1 ? n : 1) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}