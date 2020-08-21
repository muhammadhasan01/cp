#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")
 
#include <bits/stdc++.h>
 
 
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int N = 7, W = 110;
const int INF = 1e9;
 
int w, h;
int col, n;
vector<pii> carp;
vector<int> perm;
 
bool simulate(int mask){
    vector<pii> v;
    for (int ix=0;ix<n;ix++){
        int i = perm[ix];
        if (mask & (1 << i)){
            v.emplace_back(carp[i].se, carp[i].fi);
        } else{
            v.emplace_back(carp[i].fi, carp[i].se);
        }
    }
    int last[w];
    fill(last, last + w, 0);
    for (auto cur_carp : v){
        int a = cur_carp.fi;
        int b = cur_carp.se;
 
        int mn = INF;
        for (int i=0;i<w;i++){
            mn = min(mn, last[i]);
        }
        if (mn == h) return 1;
        if (h - mn < b) return 0;
        int bef = INF, cnt = 0;
        int mul = -1;
        for (int i=0;i<w;i++){
            if (bef == last[i]){
                cnt++;
            } else{
                if (bef == mn && cnt >= a){
                    mul = i - cnt;
                    break;
                }
                bef = last[i];
                cnt = 1;
            }
        }
        if (mul == -1){
            if (bef == mn && cnt >= a){
                mul = w - cnt;
            }
        }
        if (mul == -1) return 0;
        for (int i=mul;i<mul + a;i++){
            last[i] = last[i] + b;
        }
    }
    int mn = INF;
    for (int i=0;i<w;i++){
        mn = min(mn, last[i]);
    }
    return mn == h;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> w >> h;
    cin >> col;
    for (int i=1;i<=col;i++){
        int a, b, c;
        cin >> a >> b >> c;
        while (a--){
            carp.emplace_back(b, c);
        }
    }
    n = carp.size();
    for (int i=0;i<n;i++){
        perm.pb(i);
    }
    int lup = 1;
    for (int i=1;i<=n;i++){
        lup *= i;
    }
    int mxmask = (1 << n);
    while (lup--){
        for (int i=0;i<mxmask;i++){
            if (simulate(i)){
                cout << "yes" << el;
                return 0;
            }
        }
        next_permutation(perm.begin(), perm.end());
    }
    cout << "no" << el;
 
    return 0;
}