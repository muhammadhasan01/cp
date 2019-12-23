#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int tc;
int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        set<int, greater<int>> s;
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            if (x % 2 == 0) {
                s.insert(x);
            }
        }
        int ans = 0;
        while (!s.empty()) {
            int k = *s.begin();
            s.erase(s.begin());
            ans++;
            if (k % 4 == 0) {
                s.insert(k / 2);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
