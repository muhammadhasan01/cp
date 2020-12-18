#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10, SZ = 4e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int n;
pii ar[N]; // out, in
map<int, int> getid;
int conv[SZ + 1];

int ans;

pii t[SZ * 4]; // waste, count
pii merge(pii a, pii b){
    if (a.fi == b.fi){
        return mp(a.fi, (a.se + b.se) % MOD);
    }
    return min(a, b);
}
pii merge(int v){
    return merge(t[v * 2], t[v * 2 + 1]);
}
void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = mp(INF, 0);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v] = mp(INF, 0);
}
void update(int v, int tl, int tr, int l, int r, pii val){
    assert(l == r);
    if (l > r || r < tl || tr < l) return;
    else if (l <= tl && tr <= r){
        t[v] = merge(t[v], mp(val.fi + conv[SZ] - conv[r], val.se));
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    t[v] = merge(v);
}
pii ask(int v, int tl, int tr, int l, int r){
    if (l > r || r < tl || tr < l) return mp(INF, 0);
    else if (l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return merge(ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        getid[ar[i].fi] = 1;
        getid[ar[i].se] = 1;
    }
    {
        int tempid = 1;
        for (auto& x : getid){
            x.se = tempid++;
            conv[x.se] = x.fi;
        }
        conv[SZ] = INF;
        for (int i=1;i<=n;i++){
            ar[i].fi = getid[ar[i].fi];
            ar[i].se = getid[ar[i].se];
        }
    }
    sort(ar + 1, ar + n + 1);

    build(1, 0, SZ - 1);
    update(1, 0, SZ - 1, 0, 0, mp(0, 1));

    int mx = 0;
    for (int i=1;i<=n;i++){
        mx = max(mx, ar[i].se);
    }
    for (int i=1;i<=n;i++){
        auto temp = ask(1, 0, SZ - 1, 0, ar[i].se);
        temp.fi -= conv[SZ] - conv[ar[i].se];
        update(1, 0, SZ - 1, ar[i].fi, ar[i].fi, temp);
    }
    int mn = INF;
    for (int i=mx + 1;i<SZ;i++){
        auto temp = ask(1, 0, SZ - 1, i, i);
        if (temp.se == 0) continue;
        mn = min(mn, temp.fi - (conv[SZ] - conv[i]));
    }
    for (int i=mx + 1;i<=SZ;i++){
        auto temp = ask(1, 0, SZ - 1, i, i);
        temp.fi -= (conv[SZ] - conv[i]);
        if (temp.fi == mn){
            ans = (ans + temp.se) % MOD;
        }
    }
    cout << ans << el;

    return 0;
}