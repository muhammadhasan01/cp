#include <bits/stdc++.h>
using namespace std;

int a1, a2, k1, k2, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a1 >> a2 >> k1 >> k2 >> n;
    cout << max(0, n - (a1 * (k1 - 1) + a2 * (k2 - 1))) << " ";
    if (k1 > k2) {
        swap(a1, a2);
        swap(k1, k2);
    }
    int dpt = min(a1, n / k1);
    n -= dpt * k1;
    int pdt = min(a2, n / k2);
    cout << dpt + pdt << '\n';

    return 0;
}
