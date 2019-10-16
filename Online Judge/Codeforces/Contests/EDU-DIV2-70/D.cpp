#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int tc;
long long n;

void solve() {

    long long l = 0, r = 1e5, ans;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (mid * mid + mid + 1 <= n) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    int temp = n - (ans * ans + ans + 1);
    cout << "133";
    for (int i = 1; i <= temp; i++)
        cout << "7";
    cout << "1";
    for (int i = 1; i <= ans; i++)
        cout << "3";
    cout << "7";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        solve();
    }


    return 0;
}
