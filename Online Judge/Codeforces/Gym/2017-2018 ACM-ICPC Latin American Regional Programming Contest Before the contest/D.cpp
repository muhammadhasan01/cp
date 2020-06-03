// author : Mastre
#include <bits/stdc++.h>

#pragma gcc optimization("O2");

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

const int N = 1e5 + 10;

int n, c, q;

pii getrange(int a, int b, int s){
    int temp = s + b;
    int x = (a + ((ll)s * s) % n) % n;
    int y = (a + ((ll)temp * temp) % n) % n;
    return mp(min(x, y), max(x, y));
}

unordered_map<int, int> t[4 * N];
int lazy[4 * N];
void build(int v, int tl, int tr){
    if (tl == tr){
        // t[v][1] = 1; 
        lazy[v] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    // for (auto x : t[v * 2]){
    //     t[v][x.fi] = x.se;
    // }
    // for (auto x : t[v * 2 + 1]){
    //     t[v][x.fi] += x.se;
    // }
}

void push(int v, int range){
    if (lazy[v] == 0) return;
    int l = v * 2;
    int r = v * 2 + 1;
    lazy[l] = lazy[v];
    lazy[r] = lazy[v];
    // t[l].clear();
    // t[l][lazy[v]] = (range + 1) / 2;
    // t[r].clear();
    // t[r][lazy[v]] = (range) / 2;

    lazy[v] = 0;
}

int tl, tr, l, r, col;
void update(int v){
    if (l > tr || r < tl) return;
    else if (l <= tl && tr <= r){
        lazy[v] = col;
        // t[v].clear();
        // t[v][col] = tr - tl + 1;
        return;
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    swap(tr, tm);
    update(v * 2);
    swap(tr, tm);
    tl = tm + 1;
    update(v * 2 + 1);
    
    // t[v].clear();
    // for (auto x : t[v * 2]){
    //     t[v][x.fi] = x.se;
    // }
    // for (auto x : t[v * 2 + 1]){
    //     t[v][x.fi] += x.se;
    // }
}

int ask(int v, int tl, int tr, int l, int r, int col){
    if (l > r) return 0;
    else if (l <= tl && tr <= r){
        if (lazy[v]){
            if (lazy[v] == col) return tr - tl + 1;
            else return 0;
        }
        int tm = (tl + tr) / 2;
        return ask(v * 2, tl, tm, l, min(tm, r), col) + ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, col);
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return ask(v * 2, tl, tm, l, min(tm, r), col) + ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, col);
}

void pushall(int v, int tl, int tr){
    if (tl == tr) return;
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    pushall(v * 2, tl, tm);
    pushall(v * 2 + 1, tm + 1, tr);
}

int askisi(int v, int tl, int tr, int l, int r){
    if (l > r) return 0;
    else if (l <= tl && tr <= r){
        if (lazy[v]){
            return lazy[v];
        }
        int tm = (tl + tr) / 2;
        return askisi(v * 2, tl, tm, l, min(tm, r)) + askisi(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return askisi(v * 2, tl, tm, l, min(tm, r)) + askisi(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c >> q;
    build(1, 0, n - 1);
    while (q--){
        int p, x, a, b;
        cin >> p >> x >> a >> b;

        int s = ask(1, 0, n - 1, 0, n - 1, p);
        pii range = getrange(a, b, s);
        tl = 0;
        tr = n - 1;
        l = range.fi;
        r = range.se;
        col = x;
        update(1);
    }
    int ans = 0;
    unordered_map<int, int> temp;
    pushall(1, 0, n - 1);
    for (int i=0;i<n;i++){
        temp[askisi(1, 0, n - 1, i, i)]++;
    }
    for (auto x : temp) ans = max(ans, x.se);
    cout << ans << el;

    return 0;
}