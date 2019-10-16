#include <bits/stdc++.h>
using namespace std;

int q;
int n;
string a, b;

int c(int k) {
    if (k <= 2) return 1;
    return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n >> a >> b;
        int x = 1, y = 1;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int p = a[i] - '0', q = b[i] - '0';
            p = c(p), q = c(q);
            if (x == 1) {
                if (p == 2) {
                    if (q == 1) {
                        flag = false;
                    } else {
                        x = 2;
                    }
                }
            } else {
                if (q == 2) {
                    if (p == 1) {
                        flag = false;
                    } else {
                        x = 1;
                    }
                }
            }
            if (!flag) break;
        }
        if (x != 2) flag = false;
        puts(flag ? "YES" : "NO");
    }

    return 0;
}
