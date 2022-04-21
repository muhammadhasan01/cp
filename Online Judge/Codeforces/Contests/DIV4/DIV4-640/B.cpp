#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        vector<int> ans(k - 1, 1);
        vector<int> res(k - 1, 2);
        int res1 = n - (k - 1);
        int res2 = n - 2 * (k - 1);
        if (res1 > 0 && res1 & 1) {
            cout << "YES" << '\n';
            for (auto& e : ans) cout << e << " ";
            cout << n - (k - 1) << '\n';
        } else if (res2 > 0 && res2 % 2 == 0) {
            cout << "YES" << '\n';
            for (auto& e : res) cout << e << " ";
            cout << n - 2 * (k - 1) << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }


    return 0;
}