#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

template<typename T>
struct Compresser {
    vector<T> nums;
    
    Compresser() {}

    Compresser(vector<T>& v) {
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
 
    int getId(T x) {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    }

    T getValue(int id) {
        return nums[id - 1];
    }
 
    int getLen() {
        return nums.size();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    Compresser<int> compresser; 
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        compresser.add(a[i]);
    }
    int numUpdate = -1;
    vector<pair<int, int>> updates;
    vector<tuple<int, int, int, int>> queries;
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            queries.emplace_back(i, l, r, numUpdate);
        } else if (tp == 2) {
            int p, x;
            cin >> p >> x;
            --p;
            compresser.add(x);
            numUpdate++;
            updates.emplace_back(p, x);
        }
    }
    compresser.finish();
    for (int i = 0; i < n; i++) {
        a[i] = compresser.getId(a[i]);
    }
    for (auto& [p, x] : updates) {
        x = compresser.getId(x);
    }
    const int BLOCK = ceil(pow(n, 2.0 / 3.0));
    sort(queries.begin(), queries.end(), [&](auto& lhs, auto& rhs) {
        auto [li, ll, lr, lNumUpdate] = lhs;
        auto [ri, rl, rr, rNumUpdate] = rhs;
        if (ll / BLOCK != rl / BLOCK) {
            return ll / BLOCK < rl / BLOCK;
        }
        if (lNumUpdate / BLOCK != rNumUpdate / BLOCK) {
            return lNumUpdate / BLOCK < rNumUpdate / BLOCK;
        }
        return lr < rr;
    });
    vector<int> cnt(MAX), sz(MAX);

    auto add = [&](int x) -> void {
        --sz[cnt[x]];
        ++cnt[x];
        ++sz[cnt[x]];
    };

    auto del = [&](int x) -> void {
        --sz[cnt[x]];
        --cnt[x];
        ++sz[cnt[x]];
    };

    auto handleUpdate = [&](int curNum, int l, int r) -> void {
        assert(curNum != -1);
        auto& [p, x] = updates[curNum];
        if (l <= p && p <= r) {
            del(a[p]);
            add(x);
        }
        swap(a[p], x);
    };

    int L = 0, R = -1;
    int curNum = -1;
    vector<int> ans(q, -1);
    for (auto [i, l, r, num] : queries) {
        while (R < r) {
            add(a[++R]);
        }
        while (L > l) {
            add(a[--L]);
        }
        while (R > r) {
            del(a[R--]);
        }
        while (L < l) {
            del(a[L++]);
        }
        while (curNum < num) {
            handleUpdate(++curNum, l, r);
        }
        while (curNum > num) {
            handleUpdate(curNum--, l, r);
        }
        int res = 1;
        while (sz[res] > 0) {
            ++res;
        }
        ans[i] = res;
     }
     for (int i = 0; i < q; i++) {
        if (ans[i] == -1) {
            continue;
        }
        cout << ans[i] << '\n';
     }
    
    return 0;
}