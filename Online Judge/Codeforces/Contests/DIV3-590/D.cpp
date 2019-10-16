#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;
string s;
int bit[N][30];

void add(int t, int x, int val) {
    for (; x <= n; x += x & -x) {
        bit[x][t] += val;
    }
}

int get(int t, int x) {
    int ret = 0;
    for (; x > 0; x -= x & -x) {
        ret += bit[x][t];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    s = '#' + s;
    for (int i = 1; i <= n; i++) {
        int pos = s[i] - 'a';
        add(pos, i, 1);
    }
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            char k;
            cin >> p >> k;
            int x = k - 'a';
            int pos = s[p] - 'a';
            add(pos, p, -1);
            add(x, p, 1);
            s[p] = k;
        } else {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for (int i = 0; i < 26; i++) {
                int cur = get(i, r) - get(i, l - 1);
                if (cur > 0) ans++;
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
