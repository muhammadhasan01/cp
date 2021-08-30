#include <bits/stdc++.h>

using namespace std;

struct vertex {
    int val;
    vertex *l, *r;
    vertex(int val) : val(val), l(NULL), r(NULL) { }
    vertex(vertex* l, vertex* r) : val(0), l(l), r(r) {
        if (l) val += l->val;
        if (r) val += r->val;
    }
};
typedef vertex* pvertex;

const int N = 2e5 + 5;

pvertex psegtree[N];

pvertex build(int s, int e) {
    if (s == e)
        return new vertex(0);
    int mid = (s + e) >> 1;
    return new vertex(build(s, mid), build(mid + 1, e));
}

pvertex update(pvertex v, int s, int e, int pos, int val) {
    if (s == e && s == pos)
        return new vertex(val);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(update(v->l, s, mid, pos, val), v->r);
    else
        return new vertex(v->l, update(v->r, mid + 1, e, pos, val));
}

int getQuery(pvertex v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return 0;
    if (l <= s && e <= r) return v->val;
    int mid = (s + e) >> 1;
    int p1 = getQuery(v->l, s, mid, l, r);
    int p2 = getQuery(v->r, mid + 1, e, l, r);
    return p1 + p2;
}

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
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin() + 1;
    }
    int len = nums.size();
    vector<int> cnt(len + 1);
    psegtree[0] = build(0, len);
    for (int i = 1; i <= n; i++) {
        psegtree[i] = update(psegtree[i - 1], 0, len, a[i], ++cnt[a[i]]);
    }
    auto getResult = [&](int l, int r, int val) -> int {
        int ret = getQuery(psegtree[r], 0, len, 0, val);
        ret -= getQuery(psegtree[l - 1], 0, len, 0, val);
        return ret;
    };
    vector<long long> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= n; k++) {
            if (1LL * k * (i - 1) + 2 > (long long) n) {
                break;
            }
            int l = k * (i - 1) + 2;
            int r = min(n, k * i + 1);
            int res = getResult(l, r, a[i] - 1);
            ans[k] += res;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}