#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    map<int, vector<int>> in, out;
    set<int> pos;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int l = a;
        int r = a + b;
        pos.emplace(l);
        pos.emplace(r);
        in[l].emplace_back(i);
        out[r].emplace_back(i);
    }
    vector<long long> ans(n + 1);
    set<int> st;
    int last = 0;
    for (int p : pos) {
        if (out.count(p)) {
            int k = (int) st.size();
            for (int i : out[p]) {
                st.erase(i);
            }
            if ((int) st.size() < k && k > 0) {
                ans[k] += 1LL * (p - last);
            }
            last = p;
        }
        if (in.count(p)) {
            int k = (int) st.size();
            for (int i : in[p]) {
                st.emplace(i);
            }
            if ((int) st.size() > k && k > 0) {
                ans[k] += 1LL * (p - last);
            }
            last = p;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    
    return 0;
}