#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int K = 1e6;
const long long M = 1e18;
int q;
int k;
long long pre[N], pref[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long k = 0;
    for (int i = 1; i <= K; i++) {
        pre[i] = (floor(log10(i)) + 1) + pre[i - 1];
        pref[i] = pre[i] + pref[i - 1];
        if (pref[i] > M) {
            cerr << i << " " << pref[i] << '\n';
            break;
        }
    }
    cerr << pref[K] << '\n';
    cin >> q;
    while (q--) {
        cin >> k;
        int it = lower_bound(pref, pref + K + 1, k) - pref - 1;
        int dif = k - pref[it];
        int pos = lower_bound(pre, pre + K + 1, dif) - pre - 1;
        int difp = dif - pre[pos];
        string x = to_string(pos + 1);
        cout << x[difp - 1] << '\n';
    }

    return 0;
}
