#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int MX = 4;

int n, q;
vector<int> t[4 * N][MX + 1];
int lazy[4 * N];

vector<int> base = {0, 0, 0};

vector<int> merge(int tl, int tr, const vector<int>& a, const vector<int>& b){
    vector<int> ret(3);
    int tm = (tl + tr) / 2;
    int le = tm - tl + 1;
    int ri = tr - tm;
    ret[0] = a[0];
    if (a[0] == le) ret[0] += b[0];
    ret[1] = max(max(a[1], b[1]), a[2] + b[0]);
    ret[2] = b[2];
    if (b[2] == ri) ret[2] += a[2];
    return ret;
}

void swift(int v, int val) {
    if (val > 0){
        for (int i=MX;i>=0;i--){
            if (i + val <= MX){
                t[v][i + val] = t[v][i];
            }
        }
        for (int i=0;i<val;i++) t[v][i] = base;
    } else if (val < 0){
        for (int i=0;i<=MX;i++){
            if (i + val >= 0){
                t[v][i + val] = t[v][i];
            }
        }
        for (int i=MX + val + 1;i<=MX;i++) t[v][i] = base;
    }
}
void build(int v, int tl, int tr){
    if (tl == tr){
        int len = tr - tl + 1;
        t[v][0].resize(3, len);
        for (int i=1;i<=MX;i++){
            t[v][i] = base;
        }
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    for (int i=0;i<=MX;i++){
        t[v][i] = merge(tl, tr, t[v * 2][i], t[v * 2 + 1][i]);
    }
}
void push(int v){
    if (lazy[v]){
        lazy[v * 2] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        swift(v * 2, lazy[v]);
        swift(v * 2 + 1, lazy[v]);
        lazy[v] = 0;
    }
}
void update(int v, int tl, int tr, int l, int r, int val){
    if (l > r || tr < l || r < tl) return;
    if (l <= tl && tr <= r){
        lazy[v] += val;
        swift(v, val);
        return;
    }
    int tm = (tl + tr) / 2;
    push(v);
    update(v * 2, tl, tm, l, r, val);
    update(v * 2 + 1, tm + 1, tr, l, r, val);
    for (int i=0;i<=MX;i++){
        t[v][i] = merge(tl, tr, t[v * 2][i], t[v * 2 + 1][i]);
    }
}
vector<int> ask(int v, int tl, int tr, int l, int r){
    if (l > r || tr < l || r < tl) return base;
    if (l <= tl && tr <= r) return t[v][0];
    int tm = (tl + tr) / 2;
    push(v);
    return merge(tl, tr, ask(v * 2, tl, tm, l, r), ask(v * 2 + 1, tm + 1, tr, l, r));
}
int get0(){
    auto temp = ask(1, 0, n, 0, n);
    int ret = 0;
    for (auto& x : temp) ret = max(ret, x);
    return ret;
}

void solve(){
    int id, op, l, r;
    cin >> id >> op >> l >> r;
    if (op == 0){
        update(1, 0, n, l, r, 1);
    } else{
        update(1, 0, n, l, r, -1);
    }
    cout << get0() << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    build(1, 0, n);
    for (int i=0;i<MX;i++){
        int len;
        cin >> len;
        for (int j=0;j<len;j++){
            int l, r;
            cin >> l >> r;
            update(1, 0, n, l, r, 1);
        }
    }
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}