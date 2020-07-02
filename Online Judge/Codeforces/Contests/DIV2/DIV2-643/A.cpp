#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> k;
        bool flag = false;
        for (int i = 1; i <= min(1000LL, k - 1); i++) {
            string temp = to_string(a);
            long long mini = 15, maxi = 0;
            for (auto& e : temp) {
                long long x = (long long) (e - '0');
                mini = min(mini, x);
                maxi = max(maxi, x);
                if (e == '0') {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            a = a + mini * maxi;
        }
        cout << a << '\n';
    }

    return 0;
}