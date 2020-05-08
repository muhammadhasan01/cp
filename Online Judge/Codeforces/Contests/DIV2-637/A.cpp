#include <bits/stdc++.h>

using namespace std;

int tc;
int n, a, b, c, d;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b >> c >> d;
        int lowz = (a - b) * n;
        int hgh = (a + b) * n;
        bool flag = false;
        for (int i = c - d; i <= c + d; i++) {
            if (lowz <= i && i <= hgh) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }

    return 0;
}