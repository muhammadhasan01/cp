#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
long long n;
int k;
long long a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    int pos = -1;
    long long need = -1;
    long long ans = 1e18 + 5;
    for (int i = 1; i <= k; i++) {
        long long cur = n % a[i];
        if (cur < ans) {
            ans = cur;
            pos = i;
            need = (n / a[i]);
        }
    }
    cout << pos << ' ' << need << '\n';

    return 0;
}
