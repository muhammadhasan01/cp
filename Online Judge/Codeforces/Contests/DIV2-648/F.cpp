#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 5;

int tc;
int n;
int a[N], b[N];

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
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        if (n & 1) {
            int mid = (n + 1) / 2;
            if (a[mid] != b[mid]) {
                cout << "No" << '\n';
                continue;
            } else if (n == 1) {
                cout << "Yes" << '\n';
                continue;
            }
        }
        int k = n / 2;
        map<pair<int, int>, int> mp;
        for (int i = 1; i <= k; i++) {
            int x = min(a[i], a[n - i + 1]);
            int y = max(a[i], a[n - i + 1]);
            mp[make_pair(x, y)]++;
        }
        bool flag = true;
        for (int i = 1; i <= k; i++) {
            int x = min(b[i], b[n - i + 1]);
            int y = max(b[i], b[n - i + 1]);
            if (--mp[make_pair(x, y)] < 0) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }

    return 0;
}