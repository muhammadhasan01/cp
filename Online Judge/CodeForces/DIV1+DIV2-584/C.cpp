#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int tc;
int n;
string s;
int ans[N], a[N];

bool check(int x) {
    bool flag = false;
    int m = 0;
    int last = -1, first = n;
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';
        if (c < x) {
            ans[i] = 1;
            last = i;
            a[++m] = c;
        } else if (c > x) {
            ans[i] = 2;
            first = min(first, i);
        }
    }
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';
        if (c == x) {
            if (i < first) ans[i] = 2;
            else if (i > last) ans[i] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == 2) a[++m] = (s[i] - '0');
    }
    for (int i = 1; i <= m - 1; i++) {
        if (a[i] > a[i + 1]) return false;
    }
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> s;
        bool ok = false;
        for (int i = 0; i <= 9; i++) {
            if (check(i)) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "-" << '\n';
        }
    }

    return 0;
}
