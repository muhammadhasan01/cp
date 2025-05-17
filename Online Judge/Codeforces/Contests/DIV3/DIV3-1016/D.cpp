#include <bits/stdc++.h>

using namespace std;
 

long long getVal(int n, long long x, long long y) {
    if (n == 1) {
        if (x == 1 && y == 1) {
            return 1;
        }
        if (x == 1 && y == 2) {
            return 4;
        }
        if (x == 2 && y == 1) {
            return 3;
        }
        return 2;
    }
    long long half = 1LL << (n - 1);
    long long blockSize = 1LL << (2 * (n - 1));
    if (x <= half && y <= half) {
        return getVal(n - 1, x, y);
    }
    if (x > half && y > half) {
        return blockSize + getVal(n - 1, x - half, y - half);
    }
    if (x > half && y <= half) {
        return 2LL * blockSize + getVal(n - 1, x - half, y);
    }
    return 3LL * blockSize + getVal(n - 1, x, y - half);
}
 
pair<long long, long long> getCoord(int n, long long d) {
    if (n == 1) {
        if (d == 1) {
            return {1, 1};
        }
        if (d == 2) {
            return {2, 2};
        }
        if (d == 3) {
            return {2, 1};
        }
        return {1, 2};
    }
    long long half = 1LL << (n - 1);
    long long blockSize = 1LL << (2 * (n - 1));
    if (d <= blockSize) {
        return getCoord(n - 1, d);
    }
    if (d <= 2LL * blockSize) {
        auto [x, y] = getCoord(n - 1, d - blockSize);
        return {x + half, y + half};
    }
    if (d <= 3LL * blockSize) {
        auto [x, y] = getCoord(n - 1, d - 2 * blockSize);
        return {x + half, y};
    }
    auto [x, y] = getCoord(n - 1, d - 3 * blockSize);
    return {x, y + half};
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        string op;
        cin >> op;
        if (op == "<-") {
            long long d;
            cin >> d;
            auto [x, y] = getCoord(n, d);
            cout << x << " " << y << "\n";
        } else {
            long long x, y;
            cin >> x >> y;
            long long res = getVal(n, x, y);
            cout << res << "\n";
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
