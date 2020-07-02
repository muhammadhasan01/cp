#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int n, m;
long long a[N];
long long maks;
long long nums;

string bin(long long x) {
    if (x <= 1) return to_string(x);
    return bin(x / 2) + bin(x % 2);
}

bool can(long long x) {
    long long pos = x + 1;
    for (int i = 1; i <= n; i++) {
        if (x >= a[i]) pos--;
    }
    return (pos <= nums);
}

bool check(long long x) {
    long long pos = x + 1;
    for (int i = 1; i <= n; i++) {
        if (x == a[i]) return false;
        if (x > a[i]) pos--;
    }
    return (pos == nums);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            a[i] = 0;
            for (int j = 1, k = m - 1; j <= m; j++, k--) {
                char x;
                cin >> x;
                if (x == '1') {
                    a[i] += (1LL << k);
                }
            }
        }
        maks = (1LL << m) - 1;
        nums = (maks - n + 2) / 2;
        long long l = 0, r = maks, ans = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (can(mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }
        for (long long i = max(0LL, ans - n); i <= min(maks, ans + n); i++) {
            if (check(i)) {
                ans = i;
                break;
            }
        }
        string result = bin(ans);
        while ((int) result.size() < m) {
            result = "0" + result;
        }
        cout << result << '\n';
    }

    return 0;
}