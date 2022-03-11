#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x)
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        if (l > r) {
            return 0;
        }
        return get(r) - get(l - 1);
    }
};

const int BLOCK = 550;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = *max_element(a.begin(), a.end());
    BIT<long long> bit_sum(2 * m);
    BIT<int> bit_cnt(2 * m);
    vector<int> cnt_block(BLOCK);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = x, k = 0; k <= m; j += x, k += x) {
            ans += (bit_sum.query(k + 1, j - 1) - 1LL * bit_cnt.query(k + 1, j - 1) * k);
        }
        ans += (1LL * bit_cnt.query(x + 1, m) * x);
        for (int j = 1; j * j <= x; j++) {
            int r = x / j;
            if (r < BLOCK) {
                break;
            }
            int l = max(BLOCK, x / (j + 1) + 1);
            if (l > r) {
                continue;
            }
            ans += (1LL * x * bit_cnt.query(l, r) - 1LL * j * bit_sum.query(l, r));
        }
        for (int j = 1; j < min(x, BLOCK); j++) {
            if (cnt_block[j] == 0) {
                continue;
            }
            ans += 1LL * (x % j) * cnt_block[j];
        }
        if (x < BLOCK) {
            cnt_block[x]++;
        }
        bit_sum.add(a[i], a[i]);
        bit_cnt.add(a[i], 1);
        cout << ans << " \n"[i == n - 1];
    }
    
    return 0;
}