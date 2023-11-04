#include <bits/stdc++.h>

using namespace std;

set<vector<int>> st;
vector<int> res;
vector<pair<int, int>> p;

void gen(int pos) {
    if (pos >= p.size()) {
        st.emplace(res);
        return;
    }
    int x = p[pos].first;
    int y = p[pos].second;
    // win
    {
        res[x] += 3;
        res[y] += 0;
        gen(pos + 1);
        res[x] -= 3;
        res[y] -= 0;
    }
    // draw
    {
        res[x] += 1;
        res[y] += 1;
        gen(pos + 1);
        res[x] -= 1;
        res[y] -= 1;
    }
    // lose
    {
        res[x] += 0;
        res[y] += 3;
        gen(pos + 1);
        res[x] -= 0;
        res[y] -= 3;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int x = 2; x <= 5; x++) {
        res.clear();
        p.clear();
        res.assign(x, 0);
        for (int i = 0; i < x; i++) {
            for (int j = i + 1; j < x; j++) {
                if (i == j) {
                    continue;
                }
                p.emplace_back(i, j);
            }
        }
        gen(0);
    }
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (st.find(a) == st.end()) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
    
    return 0;
}