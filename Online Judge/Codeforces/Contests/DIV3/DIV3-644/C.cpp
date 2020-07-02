#include <bits/stdc++.h>

using namespace std;

const int N = 55;

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
        int even = 0, odd = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] & 1) {
                odd++;
            } else {
                even++;
            }
        }
        
        if (even % 2 == 0 && odd % 2 == 0) {
            cout << "YES" << "\n";
        } else if (even % 2 == 1 && odd % 2 == 1) {
            sort(a + 1, a + 1 + n);
            bool flag = false;
            for (int i = 1; i < n; i++) {
                if (a[i] == a[i + 1] - 1) {
                    flag = true;
                    break;
                }
            }
            cout << (flag ? "YES" : "NO") << '\n';
        } else {
            cout << "NO" << '\n';
        }

    }

    return 0;
}