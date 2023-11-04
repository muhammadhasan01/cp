#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x)
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<char> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    set<int> st;
    for (int i = 1; i <= n + 1; i++) {
        st.emplace(i);
    }
    vector<int> ord;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        for (int x = l; x <= r; ) {
            if (st.count(x)) {
                ord.emplace_back(x);
                st.erase(x);
            }
            x = *st.upper_bound(x);
        }
    }
    vector<int> id(n + 1, -1);
    BIT<int> bit(n + 5);
    int len = ord.size();
    for (int i = 0; i < len; i++) {
        id[ord[i]] = i + 1;
        if (s[ord[i]] == '0') {
            bit.add(id[ord[i]], 1);
        }
    }
    int numOne = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            numOne++;
        }
    }
    while (q--) {
        int pos;
        cin >> pos;
        if (s[pos] == '0') {
            numOne++;
            s[pos] = '1';
            if (id[pos] != -1) {
                bit.add(id[pos], -1);
            }
        } else if (s[pos] == '1') {
            numOne--;
            s[pos] = '0';
            if (id[pos] != -1) {
                bit.add(id[pos], 1);
            }
        }
        cout << bit.get(min(len, numOne)) << '\n';
    }
    
    return 0;
}