#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    auto ask = [&](int a, int b, int c, int d) -> int {
        cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
        int res;
        cin >> res;
        return res;
    };

    int resX = -1, resY = -1;
    {
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ask(1, mid, 1, n) <= mid - 1) {
                r = mid - 1;
                resX = mid;
            } else {
                l = mid + 1;
            }
        }
    }
    {
        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ask(1, n, 1, mid) <= mid - 1) {
                r = mid - 1;
                resY = mid;
            } else {
                l = mid + 1;
            }
        }
    }
    cout << "! " << resX << ' ' << resY << endl;
    
    return 0;
}