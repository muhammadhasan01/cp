#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long sum = 0;
    int fpb = 0, maks = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += (1LL) * a[i];
        maks = max(maks, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        fpb = __gcd(fpb, maks - a[i]);
    }
    cout << ((1LL) * maks * (1LL) * n - sum) / fpb << " " << fpb << '\n';

    return 0;
}
