#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, k, pr[N], cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    pr[1] = 1;
    for (int i = 2; i <= N - 5; i++) {
        if (pr[i] == 0) {
            for (int j = i; j <= N - 5; j += i) {
                pr[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            int p = pr[x], c = 0;
            while (x % p == 0) {
                c++;
                x /= p;
            }
            cnt[p] = max(cnt[p], c);
        }
    }
    bool ok = true;
    while (k > 1) {
        int p = pr[k], c = 0;
        while (k % p == 0) {
            c++;
            k /= p;
        }
        if (cnt[p] < c) {
            ok = false;
            break;
        }
    }
    puts(ok ? "Yes" : "No");

    return 0;
}
