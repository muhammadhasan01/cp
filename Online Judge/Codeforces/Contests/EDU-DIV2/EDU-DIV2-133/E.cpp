#include <bits/stdc++.h>

using namespace std;

struct Info {
    long long pre, suf, ans, sum;
    Info() {}
    Info(long long x) : pre(max(x, 0LL)), suf(max(x, 0LL)), ans(max(x, 0LL)), sum(x) {}
    Info(const Info& l, const Info& r) {
        pre = max(l.pre, l.sum + r.pre);
        suf = max(l.suf + r.sum, r.suf);
        sum = l.sum + r.sum;
        ans = max({l.ans, r.ans, l.suf + r.pre});
    }
};

const int K = 20;
const int N = (1 << K);

int a[N];
vector<Info> t[N];

void build(int v, int s, int e) {
    int len = (e - s + 1);
    t[v].resize(len);
    if (s == e) {
        t[v][0] = Info(a[s]);
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    for (int x = 0; x < len / 2; x++) {
        t[v][x] = Info(t[v << 1][x], t[v << 1 | 1][x]);
        t[v][x + len / 2] = Info(t[v << 1 | 1][x], t[v << 1][x]);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k;
    cin >> k;
    int n = (1 << k);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int q;
    cin >> q;
    int val = 0;
    while (q--) {
        int x;
        cin >> x;
        val ^= (1 << x);
        cout << t[1][val].ans << '\n';
    }
    
    return 0;
}