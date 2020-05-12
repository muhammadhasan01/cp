#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e7;

int tc;
int n, k;
int a[N], b[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        bool can = false;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == k) {
                b[i] = 1;
                can = true;
            } else if (a[i] > k) {
                b[i] = 2;
            } else if (a[i] < k) {
                b[i] = 0;
            }
        }
        if (!can) {
            cout << "no" << '\n';
            continue;
        }
        if (n == 1 && a[1] == k) {
            cout << "yes" << '\n';
            continue;
        }
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (i < n && b[i] > 0 && b[i + 1] > 0) {
                flag = true;
                break;
            }
            if (i < n - 1 && b[i] > 0 && b[i + 2] > 0) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "yes" : "no") << '\n';
    }

    return 0;
}