#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, T TERM>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, TERM);
    }

    T combine(const T& x, const T& y) {
        return (x > y ? x : y);
    }

    void update(int v, int s, int e, int pos, T val) {
        if (s == e && s == pos) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    T get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        T p1 = get(v << 1, s, mid, l, r);
        T p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
};

const int N = 4e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> res(n + 1, vector<int>(3));
    vector<int> cnt(3);
    vector<Segtree<N, int, 0>> sgt(3); 
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        cnt[(int) (s[i - 1] - 'A')]++;
        int max_cnt = *max_element(cnt.begin(), cnt.end());
        for (int it = 0; it < 3; it++) {
            res[i][it] = res[i - 1][it];
            if (cnt[it] == max_cnt) {
                res[i][it]++;
            }
        }
        int chosen_val = *max_element(res[i].begin(), res[i].end());;
        if (i <= k) {
            ans[i] = chosen_val;
        } else {
            for (int it = 0; it < 3; it++) {
                int minpos = max(k, i - k);
                int val = sgt[it].get(1, 1, n, minpos, i - 1);
                ans[i] = max(ans[i], res[i][it] + val);
                if (i >= 2 * k) {
                    int curval = sgt[it].get(1, 1, n, k, i - k);
                    chosen_val = max(chosen_val, res[i][it] + curval);
                }
            }
        }
        for (int it = 0; it < 3; it++) {
            sgt[it].update(1, 1, n, i, chosen_val - res[i][it]);
        }
    }
    cout << ans[n] << '\n';
    
    return 0;
}