#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> divisors[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }
    
    int n, k;
    cin >> n >> k;
    vector<set<int>> c(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            c[i].emplace(x);
        }
    }

    int ans = 0;

    auto handle = [&](int y) {
        int x = y - 1;
        if (x < 0) {
            x = n - 1;
        }
        set<int> res;
        for (int val : c[y]) {
            for (int div : divisors[val]) {
                if (c[x].count(div)) {
                    res.emplace(div);
                }
            }
        }
        set<int> st;
        for (int val : c[x]) {
            if (res.count(val)) {
                continue;
            }
            st.emplace(val);
        }
        for (int rep = 0; rep < n; rep++) {
            if (st.empty()) {
                break;
            }
            ans++;
            int l = x - 1;
            if (l < 0) {
                l = n - 1;
            }
            set<int> nst;
            for (int val : st) {
                for (int div : divisors[val]) {
                    if (c[l].count(div)) {
                        nst.emplace(div);
                    }
                }
            }
            st.swap(nst);
            x = l;
        }
    };

    for (int i = 0; i < n; i++) {
        handle(i);
    }

    cout << ans << '\n';
    
    return 0;
}