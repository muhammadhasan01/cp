#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, T val) {
        for ( ; x > 0; x -= x & -x)
            bit[x] = max(bit[x], val);
    }

    bool get(int x, T y) {
        for ( ; x <= n; x += x & -x) {
            if (bit[x] > y) {
                return true;
            }
        }
        return false;
    }
};

template<typename T>
struct compress {
    vector<T> nums;
    
    compress(vector<T>& v) {
        nums.assign(v.begin(), v.end());
        finish();
    }

    void add(T x) {
        nums.emplace_back(x);
    }

    void finish() {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    }

    int get_id(T x) {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    }

    int get_len() {
        return nums.size();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> vb(n), vi(n), vr(n);
    for (int i = 0; i < n; i++) {
        cin >> vb[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vi[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vr[i];
    }
    compress<int> ci(vi), cr(vr);
    vector<tuple<int, int, int>> a(n);
    for (int i = 0; i < n; i++) {
        auto& [B, I, R] = a[i];
        B = vb[i];
        I = vi[i];
        R = vr[i];
    }
    int m = n + 5;
    BIT<int> bit(m);
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < i && get<0>(a[j]) > get<0>(a[i])) {
            auto [B, I, R] = a[j];
            int pi = ci.get_id(I);
            int pj = cr.get_id(R);
            bit.add(pi, pj);
            j++;
        }
        auto [B, I, R] = a[i];
        int pi = ci.get_id(I);
        int pr = cr.get_id(R);
        if (bit.get(pi + 1, pr)) {
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}