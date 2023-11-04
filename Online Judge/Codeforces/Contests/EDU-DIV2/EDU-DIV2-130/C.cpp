#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int K = 3;

void solve() {
    int n;
    cin >> n;
    vector<char> a(n);
    set<int> st;
    vector<set<int>> pos(K);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.emplace(i);
        pos[a[i] - 'a'].emplace(i);
    }
    vector<char> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        int at = *st.begin();
        char ai = a[at];
        if (ai == b[i]) {
            st.erase(at);
            pos[ai - 'a'].erase(at);
            continue;
        }
        if (b[i] == 'a') {
            cout << "NO" << "\n";
            return;
        }
        int pos0 = (pos[0].empty() ? INF : *pos[0].begin());
        int pos1 = (pos[1].empty() ? INF : *pos[1].begin());
        int pos2 = (pos[2].empty() ? INF : *pos[2].begin());
        if (b[i] == 'b') {
            if (pos1 >= pos2) {
                cout << "NO" << '\n';
                return;
            }
            st.erase(pos1);
            pos[1].erase(pos1);
        } else if (b[i] == 'c') {
            if (pos2 >= pos0) {
                cout << "NO" << '\n';
                return;
            }
            st.erase(pos2);
            pos[2].erase(pos2);
        }
    }
    cout << "YES" << '\n';
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