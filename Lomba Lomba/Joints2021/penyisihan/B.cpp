// ga besa aq kalo query :(
#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

const int N = 1e5 + 5;

int n, q;
int a[N];
int pre[N], suf[N];
pair<int, int> p[N];
pair<int, int> b[N];

// this is stupid, but oh well
int solve_one() {
    for (int i = 0; i < n; i++) {
        b[i] = make_pair(a[i], i);
    }
    sort(b, b + n, greater<pair<int, int>>());
    int l = b[0].second, r = b[0].second;
    int mini = a[l];
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int cl = l, cr = r;
        while (b[i].second < l) {
            mini = min(mini, a[--l]);
        }
        while (b[i].second > r) {
            mini = min(mini, a[++r]);
        }
        if (b[i].first == b[i + 1].first) continue;
        if (i > 0 && cl == l && cr == r) continue;
        int pref = (l == 0 ? 0 : pre[l - 1]);
        int suff = suf[r + 1];
        int maxi = max(pref, suff);
        if (mini <= maxi) continue;
        ret += mini - maxi;
        if (l == 0 && r == n - 1) break;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    in(n), in(q);
    for (int i = 0; i < n; i++) {
        in(a[i]);
    }
    for (int i = 0; i < q; i++) {
        in(p[i].first), in(p[i].second);
    }
    for (int i = 0; i < n; i++) {
        pre[i] = a[i];
        if (i > 0) pre[i] = max(pre[i], pre[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], a[i]);
    }
    for (int i = 0; i < q; i++) {
        a[--p[i].first] = p[i].second;
        for (int j = p[i].first; j < n; j++) {
            pre[j] = a[j];
            if (j > 0) pre[j] = max(pre[j], pre[j - 1]);
        }
        for (int j = p[i].first; j >= 0; j--) {
            suf[j] = max(suf[j + 1], a[j]);
        }
        int ans = solve_one();
        out(ans, '\n');
    }

    return 0;
}