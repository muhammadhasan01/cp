#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
pair<int, int> p[N];
set<int, greater<int>> st;
unordered_map<int, int> mp;
vector<int> g[N];
int mini[N], maks[N];
int qr[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
        g[p[i].first].push_back(p[i].second);
    }
    for (int i = 1; i <= n; i++) {
        if ((int) g[i].size() == 0) continue;
        int maks = g[i].back();
        mp[maks] = i;
        st.insert(maks);
    }
    int q;
    cin >> q;
    while (q--) {
        int len;
        cin >> len;
        for (int i = 1; i <= len; i++) {
            cin >> qr[i];
            if ((int) g[qr[i]].size() == 0) continue;
            st.erase(g[qr[i]].back());
        }
        int lenz = st.size();
        if (lenz == 0) {
            cout << 0 << " " << 0 << '\n';
        } else if (lenz == 1) {
            int cur = *(st.begin());
            int idx = mp[cur];
            cout << idx << " " << g[idx][0] << '\n';
        } else {
            auto it = st.begin();
            int idx = mp[*it];
            it++;
            cout << idx << " " << *lower_bound(g[idx].begin(), g[idx].end(), *it) << '\n';
        }
        for (int i = 1; i <= len; i++) {
            if ((int) g[qr[i]].size() == 0) continue;
            st.insert(g[qr[i]].back());
        }
    }

    return 0;
}