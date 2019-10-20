#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;
int tc;
int s, n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        map<int, bool> m;
        pair<int,int> ans;
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            int k = s - a[i];
            if (m[k] == 1) {
                int x = s - a[i], y = a[i];
                if (x > y) swap(x, y);
                ans = {x, y};
                ok = true;
                break;
            }
            m[a[i]] = 1;
        }
        if (!ok) {
            cout << "!OK" << '\n';
        } else {
            cout << ans.first << " " << ans.second << '\n';
        }
    }

    return 0;
}
