#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int B = 550;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> s(m);
    vector<bool> in_block(m);
    vector<int> block_idx;
    for (int i = 0; i < m; i++) {
        int len;
        cin >> len;
        s[i].resize(len);
        for (int& j : s[i]) {
            cin >> j;
            j--;
        }
        if (len > B) {
            block_idx.emplace_back(i);
            in_block[i] = true;
        }
    }
    int lblock = block_idx.size();
    vector<ll> ans_block(m);
    vector<ll> qr_block(m);
    vector<vector<bool>> inside(lblock, vector<bool>(n));
    vector<vector<int>> intersect(lblock, vector<int>(lblock));
    vector<int> pos_block(m);
    for (int i = 0; i < lblock; i++) {
        int id = block_idx[i];
        pos_block[id] = i;
        set<int> st;
        for (int e : s[id]) {
            st.emplace(e);
            ans_block[id] += a[e];
            inside[i][e] = true;
        }
        for (int j = 0; j < lblock; j++) {
            int idx = block_idx[j];
            for (int e : s[idx]) {
                if (st.find(e) != st.end()) {
                    intersect[i][j]++;
                }
            }
        }
    }
    auto add_num = [&](int k, ll x) -> void {
        if (in_block[k]) {
            qr_block[k] += x;
            int pos = pos_block[k];
            for (int j = 0; j < lblock; j++) {
                int id = block_idx[j];
                ans_block[id] += x * intersect[pos][j];
            }
        } else {
            for (int i : s[k]) {
                a[i] += x;
                for (int j = 0; j < lblock; j++) {
                    if (inside[j][i]) {
                        int id = block_idx[j];
                        ans_block[id] += x;
                    }
                }
            }
        }
    };
    auto get_sum = [&](int k) -> ll {
        ll ret = 0;
        if (in_block[k]) {
            ret += ans_block[k];
        } else {
            for (int i : s[k]) {
                ret += a[i];
                for (int j = 0; j < lblock; j++) {
                    if (inside[j][i]) {
                        int id = block_idx[j];
                        ret += qr_block[id];
                    }
                }
            }
        }
        return ret;
    };
    while (q--) {
        char tp;
        cin >> tp;
        if (tp == '?') {
            int k;
            cin >> k;
            --k;
            cout << get_sum(k) << '\n';
        } else if (tp == '+') {
            int k, x;
            cin >> k >> x;
            --k;
            add_num(k, x);
        }
    }
    
    return 0;
}