#include <bits/stdc++.h>

using namespace std;

int tc;
int x, y, z;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> x >> y >> z;
        vector<int> v = {x, y, z};
        set<int> st;
        st.emplace(x); st.emplace(y); st.emplace(z);
        int len = st.size();
        if (len == 3) {
            cout << "NO" << '\n';
        } else if (len == 1) {
            cout << "YES" << '\n';
            for (int i = 0; i < 3; i++) {
                cout << *st.begin() << (i == 2 ? '\n' : ' ');
            }
        } else {
            int n = *st.rbegin();
            int m = *st.begin();
            int cnt = 0;
            for (auto& e : v) if (n == e) ++cnt;
            if (cnt == 1) {
                cout << "NO" << '\n';
                continue;
            }
            cout << "YES" << '\n';
            cout << n << " " << m << " " << m << '\n';
        }
    }

    return 0;
}