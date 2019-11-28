#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n;
ll a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum & 1 || n == 1) {
        cout << "NO" << '\n';
        return 0;
    }
    sum >>= 1;
    ll c = 0, diff;
    map<ll, int> m, m2;
    m[0] = 1;
    for (int i = 1; i <= n; i++) {
        m[a[i]]++;
        c += a[i];
        diff = c - sum;
        if (m[diff] > 0) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    c = 0;
    m2[0] = 1;
    for (int i = n; i >= 1; i--) {
        m2[a[i]]++;
        c += a[i];
        diff = c - sum;
        if (m2[diff] > 0) {
            cout << "YES" << '\n';
            return 0;
        }
    }

    cout << "NO" << '\n';

    return 0;
}
