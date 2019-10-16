#include <bits/stdc++.h>
using namespace std;

int n;
map<int,int> m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > 0) m[x]++;
    }
    int ans = 0;
    for (auto e : m) {
        if (e.second > 2) {
            puts("-1");
            return 0;
        } else if (e.second == 2) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}
