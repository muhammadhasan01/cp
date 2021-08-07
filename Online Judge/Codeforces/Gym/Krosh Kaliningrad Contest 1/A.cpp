#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x)
            bit[x] = (bit[x] + val) % M;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x > 0; x -= x & -x)
            ret = (ret + bit[x]) % M;
        return ret;
    }

    T query(int l, int r) {
        T ret = (get(r) - get(l - 1)) % M;
        return (ret % M + M) % M;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> nums(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums[i - 1] = a[i];
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    vector<int> val = a;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin() + 1;
    }
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 1);
    int len = nums.size();
    long long ans = 0;
    for (int it = 0; it < 2; it++) {
        BIT<int> sum(len + 5), cnt(len + 5);
        for (int i : pos) {
            int sum_low = (a[i] == 1 ? 0 : sum.query(1, a[i] - 1));
            int cnt_low = (a[i] == 1 ? 0 : cnt.query(1, a[i] - 1));
            long long cur_low = (1LL * val[i] * cnt_low)  % M;
            cur_low = ((cur_low - sum_low) % M + M) % M;
            cur_low = (cur_low * val[i]) % M;
            int sum_high = sum.query(a[i] + 1, len + 1);
            int cnt_high = cnt.query(a[i] + 1, len + 1);
            long long cur_high = (1LL * val[i] * cnt_high) % M;
            cur_high = ((sum_high - cur_high) % M + M) % M;
            cur_high = (cur_high * val[i]) % M;
            ans = (ans + cur_high + cur_low) % M;
            sum.add(a[i], val[i]);
            cnt.add(a[i], 1);
        }
        reverse(pos.begin(), pos.end());
    }
    cout << (ans % M + M) % M << '\n';

    return 0;
}