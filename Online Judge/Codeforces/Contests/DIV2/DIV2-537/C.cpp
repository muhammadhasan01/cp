#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    long long A, B;
    cin >> n >> k >> A >> B;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    auto getAvengers = [&](int l, int r) -> int {
        return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
    };

    function<long long(int, int)> solve = [&](int l, int r) {
        int avg = getAvengers(l, r);
        if (avg == 0) {
            return A;
        }
        if (l == r) {
            return B * avg;
        }
        int m = (l + r) >> 1;
        return min(B * avg * (r - l + 1), solve(l, m) + solve(m + 1, r));
    };

    cout << solve(1, (1 << n)) << '\n';
    
    return 0;
}