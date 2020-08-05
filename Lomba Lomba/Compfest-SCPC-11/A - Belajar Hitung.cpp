#include<bits/stdc++.h>

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

int n;
pair<int, int> p[N];

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

long long F(long long x) {
    return x * (x + 1) / 2;
}

int main() {
    inpos(n);
    for (int i = 1; i <= n; i++) {
        inpos(p[i].first), inpos(p[i].second);
    }
    long long ans = 0;
    int l = 0, r = 0;
    sort(p + 1, p + 1 + n, compare);
    for (int i = 1; i <= n; i++) {
        if (p[i].second > r) {
            l = max(r + 1, p[i].first);
            r = p[i].second;
            ans += F(r) - F(l - 1);
        }
    }
    outpos(ans);
    
    return 0;
}
