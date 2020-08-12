// Author : Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10, M = 31;

typedef pair<ll, ll> pll;

int n, q;
ll ar[N][M + 1];
ll pc[N][M + 1];

pll t[4 * N][M + 1];
bool lazy[4 * N][M + 1];

pll p(pll a, pll b){
    return mp(a.fi + b.fi, a.se + b.se);
}

void build(int v, int tl, int tr){
    if (tl == tr){
        for (int i=0;i<M;i++){
            t[v][i].fi = (pc[tl][i] & 1);
            t[v][i].se = t[v][i].fi ^ 1;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    int vl = v * 2;
    int vr = vl + 1;
    build(vl, tl, tm);
    build(vr, tm + 1, tr);
    for (int i=0;i<M;i++){
        t[v][i] = p(t[vl][i], t[vr][i]);
    }
}

void push(int v, int bit){
    if (lazy[v][bit]){
        lazy[v * 2][bit] ^= 1;
        lazy[v * 2 + 1][bit] ^= 1;
        swap(t[v * 2][bit].fi, t[v * 2][bit].se);
        swap(t[v * 2 + 1][bit].fi, t[v * 2 + 1][bit].se);
    }
    lazy[v][bit] = 0;
}

void update(int v, int tl, int tr, int l, int bit){
    if (tr < l) return;
    else if (l <= tl){
        lazy[v][bit] ^= 1;
        swap(t[v][bit].fi, t[v][bit].se);
        return;
    }
    push(v, bit);
    int tm = (tl + tr) / 2;
    int vl = v * 2;
    int vr = vl + 1;
    update(vl, tl, tm, l, bit);
    update(vr, tm + 1, tr, l, bit);
    t[v][bit] = p(t[vl][bit], t[vr][bit]);
}

pll ask(int v, int tl, int tr, int l, int r, int bit){
    if (l > r) return mp(0, 0);
    else if (l <= tl && tr <= r){
        return t[v][bit];
    }
    push(v, bit);
    int tm = (tl + tr) / 2;
    int vl = v * 2;
    int vr = vl + 1;
    return p(ask(vl, tl, tm, l, min(tm, r), bit), ask(vr, tm + 1, tr, max(l, tm + 1), r, bit));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        ll temp;
        cin >> temp;
        for (int j=0;j<M;j++){
            ar[i][j] = ((temp & (1LL << j)) > 0LL);
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=0;j<M;j++){
            pc[i][j] = pc[i - 1][j] + ar[i][j];
        }
    }

    build(1, 1, n);
    while(q--){
        int tipe, x, y;
        cin >> tipe >> x >> y;
        if (tipe == 1){
            ll val = y;
            for (int i=0;i<M;i++){
                if (val & (1 << i)){
                    if (ar[x][i] == 0){
                        update(1, 1, n, x, i);
                    }
                    ar[x][i] = 1;
                } else{
                    if (ar[x][i]){
                        update(1, 1, n, x, i);
                    }
                    ar[x][i] = 0;
                }
            }
        } else{
            ll ans = 0;
            for (int i=0;i<M;i++){
                pll temp = ask(1, 1, n, max(1, x - 1), y, i);
                if (x == 1) temp.se++;
                ans += temp.fi * temp.se * (1LL << i);
            }
            cout << ans << el;
        }
    }

    return 0;
}