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
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> x;
            x += i;
            x = (x % n + n) % n;
            v[x]++;
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (v[i] > 1) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}