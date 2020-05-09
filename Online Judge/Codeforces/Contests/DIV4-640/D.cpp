#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

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
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int turn = 0;
        int moves = 0;
        int lastSum = 0;
        vector<int> ans(2);
        int l = 1, r = n;
        while (l <= r) {
            int i, cur = 0;
            bool flag = true;
            if (!turn) {
                for (i = l; i <= r; i++) {
                    cur += a[i];
                    if (cur > lastSum) {
                        flag = false;
                        break;
                    }
                } 
                l = i + 1;
            } else {
                for (i = r; i >= l; i--) {
                    cur += a[i];
                    if (cur > lastSum) {
                        flag = false;
                        break;
                    }
                }
                r = i - 1;
            }
            ans[turn] += cur;
            lastSum = cur;
            turn ^= 1;
            moves++;
            if (flag) break;
        }
        cout << moves << " " << ans[0] << " " << ans[1] << '\n';
    }

    return 0;
}