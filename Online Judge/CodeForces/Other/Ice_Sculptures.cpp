#include<bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
const int inf = 1e9;
int n;
int t[N];

int get(int x) {
    if (n/x < 3) {
        return -inf;
    } else {
        int ret = -inf;
        for (int j = 1; j <= x; j++) {
            int cur = 0;
            for (int i = j; i <= n; i += x) {
                cur += t[i];
            }
            ret = max(ret, cur);
        }
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    int ans = -inf;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans = max(ans, get(i));
            if (i * i != n) ans = max(ans, get(n/i));
        }
    }
    cout << ans << '\n';

    return 0;
}
