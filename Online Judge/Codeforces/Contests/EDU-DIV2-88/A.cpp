#include <bits/stdc++.h>

using namespace std;

int tc;
int n, m, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m >> k;
        int sz = n / k;
        if (m <= sz) {
            cout << m << '\n';
        } else {
            m -= sz;
            k--;
            int maks = m / k;
            if (m % k != 0) maks++;
            cout << sz - maks << '\n';
        }
    }

    return 0;
}