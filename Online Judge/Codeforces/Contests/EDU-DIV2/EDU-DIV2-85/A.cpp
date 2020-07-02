#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

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
            cin >> a[i] >> b[i];
        }
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (b[i] > a[i]) {
                flag = false;
                break;
            }
            if (i > 1) {
                if (a[i] < a[i - 1]) {
                    flag = false;
                    break;
                }
                if (b[i] < b[i - 1]) {
                    flag = false;
                    break;
                }
                if (a[i] - a[i - 1] < b[i] - b[i - 1]) {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    
    return 0;
}