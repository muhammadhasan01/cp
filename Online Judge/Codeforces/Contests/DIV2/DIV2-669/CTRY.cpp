#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n;
int a[N], ans[N];
int query;
bool vis[N];

void ask(int x, int y) {
    // cout << "? " << x << " " << y << endl;
    int one = a[x] % a[y];
    // cout << "? " << y << " " << x << endl;
    int two = a[y] % a[x];
    query += 2;
    if (one > two) {
        ans[x] = one;
    } else {
        ans[y] = two;
    }
    vis[max(one, two)] = 1;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    if (n == 1) {
        cout << "! " << 1 << endl;
        return 0;
    }
    iota(a + 1, a + 1 + n, 1);
    random_shuffle(a + 1, a + 1 + n);
    for (int it = 1; it <= 100; it++) {
        int last = -1, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 0) {
                ++cnt;
                if (last != -1) {
                    ask(last, i);
                    last = -1;
                } else {
                    last = i;
                }
            }
        }
        if (cnt <= 1) break;
    }
    cout << "QUERY = " << query << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
    int last = -1;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        last = i;
    }
    // cerr << last << '\n';
    if (last != -1) {
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 0) {
                ans[i] = last;
                break;
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i] << (i == n ? '\n' : ' ');
    // }
    // for (int i = 1; i <= n; i++) {
    //     cout << ans[i] << (i == n ? '\n' : ' ');
    // }
    for (int i = 1; i <= n; i++) {
        if (a[i] != ans[i]) {
            cout << "WA :(" << '\n';
            return 0;
        }
    }

    return 0;
}