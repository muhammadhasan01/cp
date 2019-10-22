#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
const int NMAX = 2e5;
int n, k, l, r;
set<pair<int,int>> st;
int le[N], ri[N];
vector<int> vle[N], vri[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    l = 1e9, r = -1e9;
    for (int i = 1; i <= n; i++) {
        cin >> le[i] >> ri[i];
        l = min(l, le[i]), r = max(r, ri[i]);
        vle[le[i]].push_back(i);
        vri[ri[i] + 1].push_back(i);
    }

    vector<int> ans;
    for (int i = l; i <= r; i++) {
        for (auto e : vle[i]) st.insert({ri[e], e});
        for (auto e : vri[i]) st.erase({ri[e], e});
        while ((int) st.size() > k) {
            auto it = st.end(); it--;
            ans.push_back((*it).second);
            st.erase(it);
        }
    }

    cout << ans.size() << '\n';
    for (auto e : ans) cout << e << ' ';
    cout << '\n';

    return 0;
}
