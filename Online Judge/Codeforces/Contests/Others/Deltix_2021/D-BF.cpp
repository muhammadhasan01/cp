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

const int N = 2e5 + 5;
const int K = 63;

int n, m, p;
int tgt;
vector<int> pos[N];
long long pre[K];

long long check(int x) {
    unordered_map<long long, int> mp;
    for (int i = 1; i <= n; i++) {
        int len = pos[i].size();
        if (len < x) break;
        vector<char> v(len, '1');
        for (int j = 0; j < x; j++) {
            v[j] = '0';
        }
        do {
            long long cur = 0;
            for (int j = 0; j < len; j++) {
                if (v[j] == '1') continue;
                int val = pos[i][j];
                cur += pre[val];
            }
            if (++mp[cur] >= tgt) {
                return cur;
            }
        } while (next_permutation(v.begin(), v.end()));
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < K; i++) {
        pre[i] = (1LL << i);
    }
    in(n), in(m), in(p);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char cc = getchar();
            if (cc == '1') {
                pos[i].emplace_back(j);
            }
        }
        getchar();
    }
    sort(pos + 1, pos + 1 + n, [&](auto& x, auto& y) {
        return x.size() > y.size();
    });
    tgt = (n + 1) / 2;
    int l = 0, r = p;
    long long ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        long long x = check(mid);
        if (x != -1) {
            ans = x;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        char cur = '0';
        if (ans & pre[i]) {
            cur = '1';
        }
        putchar(cur);
    }
    putchar('\n');

    return 0;
}