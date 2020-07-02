#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long INF = 1e18;

int n;
int t[4 * N], lazy[4 * N];
int tp[N];
long long l[N], r[N];
long long id[N], res[N];

void push(int v, int s, int e) {
    if (lazy[v] == 0) return;
    if (s == e) return;
    int mid = (s + e) >> 1;
    if (lazy[v] == 1) {
        t[v << 1] = mid - s + 1;
        t[v << 1 | 1] = e - mid;
    } else if (lazy[v] == 2) {
        t[v << 1] = t[v << 1 | 1] = 0;
    } else if (lazy[v] == 3) {
        t[v << 1] = (mid - s + 1) - t[v << 1];
        t[v << 1 | 1] = (e - mid) - t[v << 1 | 1];
        lazy[v << 1] = 3 - lazy[v << 1];
        lazy[v << 1 | 1] = 3 - lazy[v << 1 | 1];
    }
    if (lazy[v] != 3) {
        lazy[v << 1] = lazy[v];
        lazy[v << 1 | 1] = lazy[v];
    }
    lazy[v] = 0;
}

void updateRange(int v, int s, int e, int l, int r, int p) {
    if (l > r) return;
    if (l == s && e == r) {
        if (p == 1) {
            t[v] = e - s + 1;
        } else if (p == 2) {
            t[v] = 0;
        } else if (p == 3) {
            t[v] = (e - s + 1) - t[v];
        }
        if (p == 3) {
            lazy[v] = 3 - lazy[v];
        } else {
            lazy[v] = p;
        }
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), p);
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, p);
    t[v] = t[v << 1] + t[v << 1 | 1];
}

int get(int v, int s, int e, int l, int r) {
    if (l > r) return 0;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, min(r, mid));
    int p2 = get(v << 1 | 1, mid + 1, e, max(mid + 1, l), r);
    return p1 + p2;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    set<long long> st;
    st.emplace(1);
    for (int i = 1; i <= n; i++) {
        cin >> tp[i] >> l[i] >> r[i];
        st.emplace(l[i]);
        st.emplace(l[i] + 1);
        st.emplace(r[i]);
        st.emplace(r[i] + 1);
    }
    unordered_map<long long, int> mp;
    int ord = 0;
    for (auto& e : st) {
        mp[e] = ++ord;
        id[ord] = e;
    }
    for (int i = 1; i <= n; i++) {
        l[i] = mp[l[i]];
        r[i] = mp[r[i]];
        updateRange(1, 1, ord, l[i], r[i], tp[i]);
        int l1 = 1, r1 = ord, pos = 0;
        while (l1 <= r1) {
            int mid = (l1 + r1) >> 1;
            if (get(1, 1, ord, 1, mid) == mid) {
                l1 = mid + 1;
                pos = mid;
            } else {
                r1 = mid - 1;
            }
        }
        cout << id[pos + 1] << '\n';
    }

    return 0;
}