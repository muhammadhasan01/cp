#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;
    int l = 1, r = n, at = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int ans = ask(1, mid);
        if (ans + k > mid) {
            l = mid + 1;
        } else {
            r = mid - 1;
            at = mid;
        }
    }
    cout << "! " << at << endl;

    return 0;
}