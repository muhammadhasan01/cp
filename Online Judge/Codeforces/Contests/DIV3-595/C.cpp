#include <bits/stdc++.h>

using namespace std;

long long pre[30];

int q;
long long n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0] = 1;
    for (int i = 1; i <= 15; i++) {
        pre[i] = 3 * pre[i - 1];
    }

    vector<long long> v;
    for (int i = 0; i < (1 << 11); i++) {
        long long cur = 0;
        for (int j = 0; j < 11; j++) {
            if (i & (1 << j)) {
                cur += pre[j];
            }
        }
        v.push_back(cur);
    }

    sort(v.begin(), v.end());

    cin >> q;
    while (q--) {
        cin >> n;
        auto it = lower_bound(v.begin(), v.end(), n);
        cout << *it << '\n';
    }

    return 0;
}
