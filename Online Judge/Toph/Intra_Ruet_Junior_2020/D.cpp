#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
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
    putchar('\n');
}

const int N = 1e5 + 5;

int n, q;

struct BIT {
    vector<vector<int>> t;
    BIT() {
        t.assign(N, vector<int>(3, 0));
    }

    void update(int pos, const vector<int>& val) {
        for (int it = 0; it < 3; it++) {
            if (val[it] == 0) continue;
            for (int x = pos; x <= n; x += x & -x)
                t[x][it] += val[it];
        }
    }

    vector<int> get(int l, int r) {
        vector<int> ret(3);
        for (int it = 0; it < 3; it++) {
            for (int i = r; i > 0; i -= i & -i)
                ret[it] += t[i][it];
            for (int i = l - 1; i > 0; i -= i & -i)
                ret[it] -= t[i][it];
        }
        return ret;
    }
} bit[19];

void process(int i, int val) {
    for (int it = 0; it < 19; it++) {
        vector<int> cur(3);
        cur[val % 3] = 1; val /= 3;
        vector<int> before = bit[it].get(i, i);
        for (auto& e : before) e = -e;
        bit[it].update(i, before);
        bit[it].update(i, cur);
    }
}

long long query(int l, int r) {
    long long ret = 0;
    long long three = 1;
    for (int it = 0; it < 19; it++) {
        vector<int> cur = bit[it].get(l, r);
        vector<long long> res(3);
        for (int i = 0; i < 3; i++) {
            for (int j = i; j < 3; j++) {
                int k = (i + j) % 3;
                if (i == j) {
                    res[k] += (1LL) * (cur[i]) * (cur[i] - 1) / 2;
                } else {
                    res[k] += (1LL) * (cur[i]) * (cur[j]);
                }
            }
        }
        for (int k = 1; k < 3; k++) {
            ret += (1LL) * res[k] * k * three;
        }
        three = (3LL * three);
    }
    return ret;
}

int main() {
    inpos(n), inpos(q);
    for (int i = 1; i <= n; i++) {
        int val; inpos(val);
        process(i, val);
    }
    while (q--) {
        int tp, l, r;
        inpos(tp), inpos(l), inpos(r);
        if (tp == 1) {
            long long res = query(l, r);
            outpos(res);
        } else if (tp == 2) {
            process(r, l);
        }
    }
    return 0;
}