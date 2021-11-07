// kamal property
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

int n;
int ar[N];
pii ur[N];
int le[N];
int ans[N];

int bit1[N];
void upd1(int x, int val){
    while (x < N){
        bit1[x] = max(bit1[x], val);
        x += (x & (-x));
    }
}
int ask1(int x){
    int ret = 0;
    while (x){
        ret = max(ret, bit1[x]);
        x -= (x & (-x));
    }
    return ret;
}
int bit[N];
void upd(int x, int val){
    while (x){
        bit[x] = max(bit[x], val);
        x -= (x & (-x));
    }
}
int ask(int x){
    int ret = 0;
    while (x < N){
        ret = max(ret, bit[x]);
        x += (x & (-x));
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        ur[i] = mp(ar[i], -i);
    }
    sort(ur + 1, ur + n + 1);
    for (int i=1;i<=n;i++){
        int pos = -ur[i].se;
        le[pos] = ask1(pos);
        upd1(pos, pos);
    }
    for (int i=1;i<=n;i++){
        if (le[i] == 0){
            ans[i] = 0;
        } else{
            ans[i] = ask(le[i] + 1) + 1;
        }
        upd(i, ans[i]);
    }
    int mx = 0;
    for (int i=1;i<=n;i++){
        mx = max(mx, ans[i]);
    }
    cout << mx << el;

    return 0;
}