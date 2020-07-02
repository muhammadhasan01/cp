#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long n;
int a[N];
int last[N];
long long dp[N];
long long t[4 * N], lazy[4 * N];

void push(int v, int s, int e) {
    int mid = (s + e) >> 1;
    t[v*2] += (1LL) * (mid - s + 1) * lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += (1LL) * (e - mid) * lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r)
        return;
    if (l == tl && tr == r) {
        t[v] += (1LL) * (r - l + 1) * addend;
        lazy[v] += addend;
    } else {
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = (t[v*2] + t[v*2+1]);
    }
}

long long query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l <= tl && tr <= r)
        return t[v];
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) + 
           query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    for (long long i = 1; i <= n; i++) {
        update(1, 1, n, last[a[i]] + 1, i, 1);
        sum += 2LL * query(1, 1, n, 1, i) - 1LL;
        last[a[i]] = i;
    }
    long double dsum = sum;
    long double ddiv = n * n;
    cout << fixed << setprecision(12) << sum / ddiv << '\n';

    return 0;
}