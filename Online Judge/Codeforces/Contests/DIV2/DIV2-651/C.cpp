#include <bits/stdc++.h>

using namespace std;

const string playerOne = "Ashishgup";
const string playerTwo = "FastestFinger";

int tc;
long long n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        if (n == 1) {
            cout << playerTwo << '\n';
            continue;
        } else if (n == 2 || n & 1) {
            cout << playerOne << '\n';
            continue;
        } else if (n % 4 == 0) {
            while (n % 2 == 0) n /= 2;
            cout << (n == 1 ? playerTwo : playerOne) << '\n';
            continue;
        }
        n /= 2;
        int cnt = 0;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0) {
                    ++cnt;
                    n /= i;
                }
            }
        }
        if (n > 1) cnt++;
        cout << (cnt > 1 ? playerOne : playerTwo) << '\n';
    }

    return 0;
}