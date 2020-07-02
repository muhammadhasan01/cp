#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int k1, k2, k3, n, a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + k1);
    sort(a + 1 + k1, a + 1 + k1 + k2);
    sort(a + 1 + k1 + k2, a + 1 + k1 + k2 + k3);
    vector<int> lis;
    lis.push_back(a[1]);
    for (int i = 2; i <= n; i++) {
        if (lis.back() < a[i]) {
            lis.push_back(a[i]);
        } else {
            int it = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[it] = a[i];
        }
    }
    cout << n - (int) lis.size() << '\n';

    return 0;
}
