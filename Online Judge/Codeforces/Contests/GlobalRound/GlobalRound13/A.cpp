#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, q;
int a[N];
int cnt[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            cnt[a[x]]--;
            a[x] = 1 - a[x];
            cnt[a[x]]++;
        } else {
            int k;
            cin >> k;
            cout << (cnt[1] >= k) << '\n';
        }
    }

    return 0;
}