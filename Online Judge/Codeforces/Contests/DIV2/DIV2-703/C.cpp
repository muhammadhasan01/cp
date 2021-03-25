#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
    if (l >= r) return -1;
    cout << "? " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int pos = ask(1, n);
    if (pos > 1 && ask(1, pos) == pos) {
        int l = 1, r = pos, ans = 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ask(mid, pos) == pos) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << "! " << ans << endl;
    } else {
        int l = pos, r = n, ans = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ask(pos, mid) == pos) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        } 
        cout << "! " << ans << endl;
    }

    return 0;
}