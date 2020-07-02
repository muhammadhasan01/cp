#include <bits/stdc++.h>

using namespace std;

int tc;
int n, x;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> x;
        int odd = 0, even = 0;
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            if (k & 1) odd++;
            else even++;
        }
        bool flag = false;
        for (int i = 0, j = x; i <= x; i++, j--) {
            if (odd >= i && even >= j && i % 2 == 1) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }

    return 0;
}