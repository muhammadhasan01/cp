#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    int a, b, c, d, n;
    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b >> c >> d;
        int mini = (a - b) * n;
        int maxi = (a + b) * n;
        bool flag = false;
        for (int i = c - d; i <= c + d; i++) {
            if (mini <= i && i <= maxi) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }

    return 0;
}