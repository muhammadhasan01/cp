#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    map<long long, vector<int>> in;
    map<long long, vector<int>> out;
    set<long long> points = {INF};
    vector<long long> E(n);
    for (int i = 0; i < n; i++) {
        long long x, d;
        cin >> x >> d;
        long long s = x;
        long long e = x + d;
        in[s].emplace_back(i);
        out[e].emplace_back(i);
        E[i] = e;
        points.emplace(s);
        points.emplace(e);
    }
    set<pair<long long, int>> st;
    int ans = 0;
    for (long long x = 0; x < INF; x++) {
        if (in.find(x) != in.end()) {
            for (int id : in[x]) {
                st.emplace(E[id], id);
            }
        }
        if (!st.empty()) {
            st.erase(st.begin());
            ++ans;
        }
        if (out.find(x) != out.end()) {
            for (int id : out[x]) {
                pair<long long, int> cur = {E[id], id};
                if (st.find(cur) != st.end()) {
                    st.erase(cur);
                }
            }
        }
        if (st.empty()) {
            x = *points.upper_bound(x) - 1;
        }
    }
    cout << ans << '\n';
    
    return 0;
}