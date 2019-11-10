#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int q, n;
char a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        vector<int> v(26), w(26);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v[a[i] - 'a']++;
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            w[b[i] - 'a']++;
        }
        bool flag = false;
        bool galf = false;
        for (int i = 0; i < 26; i++) {
            if (v[i] != w[i]) {
                flag = true;
                break;
            }
            if (v[i] > 1 || w[i] > 1) galf = true;
        }
        if (flag) {
            cout << "NO" << '\n';
            continue;
        } else if (galf) {
            cout << "YES" << '\n';
            continue;
        }
        int x = 0, y = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = i - 1; j >= 1; j--) {
                if (a[i] > a[j]) x++;
                if (b[i] > b[j]) y++;
            }
        }
        cout << (abs(x - y) & 1 ? "NO" : "YES") << '\n';
    }

    return 0;
}
