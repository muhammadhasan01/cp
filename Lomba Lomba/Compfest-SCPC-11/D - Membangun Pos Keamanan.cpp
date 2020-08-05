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

int n, m;
int par[N], sz[N];
bitset<N> vis;

int find(int x){
    return (par[x] == x ? x : par[x] = find(par[x]));
}

void merge(int u, int v){
    int k1 = find(u);
    int k2 = find(v);
    if(k1 != k2){
        if(sz[k1] < sz[k2])swap(k1,k2);
        sz[k1] += sz[k2];
        par[k2] = k1;
    }
}

int main(){
    inpos(n), inpos(m);
    for(int i=1;i<=n;i++){
        par[i] = i;
        sz[i] = 1;
    }
    for(int i=1;i<=m;i++){
        int u,v;
        inpos(u), inpos(v);
        merge(u,v);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        int k = find(i);
        if(vis[k] == 0){
            vis[k] = 1;
            ans += sz[k]/2;
        }
    }
    outpos(ans);

    return 0;
}
