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
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    auto calc = [&](int x, int y) -> long long {
        if (x > y) {
            return 0;
        }  
        return 1LL * (x + y) * (y - x + 1) / 2;
    };
    sort(p.begin() + 1, p.end());
    BIT<int> nums(n + 5);
    BIT<long long> ones(n + 5);
    long long inv = 0;
    for (int i = 1; i <= n; i++) {
        auto [val, id] = p[i];
        inv += nums.query(id + 1, n);
        long long res = inv;
        nums.add(id, 1);
        ones.add(id, id);
        int pos = -1;
        int tgt = (i + 1) / 2;
        {
            int l = 1, r = n;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (nums.get(mid) < tgt) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                    pos = mid;
                }
            }
        }
        int L = pos - tgt + 1;
        int R = L + i - 1;
        res += calc(L, pos) - ones.get(pos);
        res += ones.query(pos + 1, n) - calc(pos + 1, R);
        cout << res << " \n"[i == n];
    }

    return 0;
}