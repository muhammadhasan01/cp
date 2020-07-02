#include <bits/stdc++.h>

using namespace std;

struct st {
    int t, l, r;
};

const int N = 2e5 + 5;

int n, qr, m;
int a[N];
st q[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> qr >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= qr; i++) {
        cin >> q[i].t >> q[i].l >> q[i].r;
    }
    for (int it = 1; it <= m; it++) {
        int x;
        cin >> x;
        for (int i = qr; i >= 1; i--) {
            if (x < q[i].l || x > q[i].r) continue;
            if (q[i].t == 1) {
                x--;
                if (x < q[i].l) x = q[i].r;
            } else {
                int pos = x - q[i].l + 1;
                int len = q[i].r - q[i].l + 1;
                int res = (len + 1) - pos;
                x = (res + q[i].l - 1);
            }
        }
        cout << a[x] << (it == m ? '\n' : ' ');
    }

    return 0;
}