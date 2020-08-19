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
const int INF = 4e8 + 10;

struct point {
    int x, y;
    bool operator<(const point& other) {
        return x < other.x;
    };
};

int n;
long long k;
point p[N];
int len;
int posY[N], bit[N];

void add(int x, int val) {
    for ( ; x <= len; x += x & -x)
        bit[x] += val;
}

int get(int x) {
    int ret = 0;
    for ( ; x > 0; x -= x & -x)
        ret += bit[x];
    return ret;
}

int main() {
    inpos(n), inpos(k);
    vector<int> values;
    for (int i = 1; i <= n; i++) {
        int x, y;
        inpos(x), inpos(y);
        p[i].x = (x - y), p[i].y = (x + y);
        values.emplace_back(p[i].y);
    }
    sort(p + 1, p + 1 + n);
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());
    function<int(int, bool)> getPos = [&] (int val, bool low) {
        if (low)
            return lower_bound(values.begin(), values.end(), val) - values.begin() + 1;
        else
            return upper_bound(values.begin(), values.end(), val) - values.begin();
    };
    len = values.size();
    for (int i = 1; i <= n; i++) {
        posY[i] = getPos(p[i].y, true);
    }
    function<bool(int)> can = [&] (int val) {
        fill(bit + 1, bit + 1 + len, 0);
        long long ret = 0;
        for (int i = 1, j = 1; i <= n; i++) {
            while (j + 1 <= i && p[i].x - p[j].x > val) add(posY[j++], -1);
            int L = getPos(p[i].y - val, true);
            int R = getPos(p[i].y + val, false);
            int res = get(R) - get(L - 1);
            ret += res;
            add(posY[i], 1);
        }
        return (ret >= k);
    };
    int l = 0, r = INF, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    outpos(ans);
    return 0;
}