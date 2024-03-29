#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
string s;
int pre[N][5];

bool can(int x) {
    for (int i = x; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < 3; j++) {
            if (pre[i][j] - pre[i - x][j] > 0) continue;
            flag = false;
            break;
        }
        if (flag) return true;
    }
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s;
        n = s.length();
        s = '#' + s;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                pre[i][j] = pre[i - 1][j];
            }
            pre[i][(int) (s[i] - '1')]++;
        }
        int l = 0, r = n, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';   
    }

    return 0;
}