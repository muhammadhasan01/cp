#include <bits/stdc++.h>

using namespace std;

const int VAL = 45;

int dp[VAL];

void solve(int n, int t) {
    int numQuery = 0;
    int lastValue = -1;

    auto ask = [&](int x) -> int {
        assert(1 <= x && x <= n);
        cout << x << endl;
        numQuery++;
        swap(x, lastValue);
        if (x == -1) return -1;
        string res;
        cin >> res;
        if (res == "PAS") return 0;
        if (res == "KEBESARAN") return 1;
        return -1;
    };

    function<bool(int, int, int, int)> DnC = [&](int l, int r, int l2, int r2) {
        if (l > r) return false;
        int len = r - l + 1;
        if (len == 1) {
            int x = ask(l);
            if (x == 0) return true;
            if (x > 0 && (l2 != -1 && r2 != -1)) return DnC(l2, r2, -1, -1);
            return ask(l) == 0;
        }
        int val = 0;
        while (dp[val] < len) val++;
        int L = l + dp[val - 2];
        int x = ask(L);
        if (x == 0) return true;
        if (x < 0 || (l2 == -1 && r2 == -1)) return DnC(min(r, L + 1), r, l, max(l, L - 1));
        return DnC(l2, r2, -1, -1);
    };

    bool result = DnC(1, n, -1, -1);
    assert(result && numQuery <= t);
}

void init() {
    dp[2] = 1, dp[3] = 2;
    for (int i = 4, x = 1, y = 1, z = -1; i < VAL; i++, x = y, y = z) {
        z = x + y;
        dp[i] = dp[i - 1] + z;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    int n, t;
    cin >> n >> t;
    solve(n, t);

    return 0;
}