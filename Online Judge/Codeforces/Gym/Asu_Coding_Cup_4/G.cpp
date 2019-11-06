#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k;
int p[N], q[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x <= k) c1 += p[k - x];
        p[x]++;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x <= k) c2 += q[k - x];
        q[x]++;
    }
    if (c1 > c2) {
        puts("MAHMOUD");
    } else if (c1 < c2) {
        puts("BASHAR");
    } else {
        puts("DRAW");
    }

    return 0;
}
