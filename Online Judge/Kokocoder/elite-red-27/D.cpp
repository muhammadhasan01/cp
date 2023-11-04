#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 1e5 + 5;

int n;
int a[N];

int ask(int x) {
    if (x > n) return INF;
    if (a[x] != 0) return a[x];
    cout << "? " << x << endl;
    cin >> a[x];
    return a[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (ask(mid) < ask(mid + 1)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << "! " << ans << endl;

    return 0;
}