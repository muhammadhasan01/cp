#include <bits/stdc++.h>
 
 
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int N = 1e4 + 10;
const int MAX = 1e4;

vector<int> prime[MAX + 5];

void initz() {
    for (int i = 1; i <= MAX; i++) {
        int x = i;
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                prime[i].emplace_back(j);
                while (x % j == 0) x /= j;
            }
        }
        if (x > 1) prime[i].emplace_back(x);   
    }
}

// Find the number of [1..m] that is coprime with x
int coprime(int x, int m) {
    int ret = 0, len = prime[x].size();
    for (int i = 0; i < (1 << len); i++) {
        int num = 1;
        for (int j = 0; j < len; j++) {
            if (i & (1 << j)) {
                num *= prime[x][j];
            }
        }
        int bit = __builtin_popcount(i);
        int curval = m / num;
        if (bit & 1) curval *= -1;
        ret += curval;
    }
    return ret;
}

// Find the number of [l..r] that is coprime with x
int findCoprime(int x, int l, int r) {
    return coprime(x, r) - coprime(x, l - 1);
}
 
int tc;
int n;
 
vector<pii> v[N]; // vector of interval in row;
 
void init(){
    for (int i=0;i<N;i++){
        v[i].clear();
    }
}
 
void add_interval(int xa, int ya, int xb, int yb){
    for (int i=xa;i<=xb;i++){
        v[i].pb(mp(ya, yb));
    }
}
 
void merge_interval(){
    for (int i=0;i<N;i++){
        if (v[i].empty()) continue;
        vector<pii> temp;
        sort(v[i].begin(), v[i].end());
        for (auto x : v[i]){
            if (temp.empty()){
                temp.pb(x);
                continue;
            }
            if (temp.back().se + 1 >= x.fi){
                temp.back().se = max(temp.back().se, x.se);
            } else{
                temp.pb(x);
            }
        }
        v[i].swap(temp);
    }
}
 
void solve(){
    cin >> n;
    init();
    for (int i=1;i<=n;i++){
        int xa, xb, ya, yb;
        cin >> xa >> ya >> xb >> yb;
        add_interval(xa, ya, xb, yb);
    }
    merge_interval();
    int res = 0;
    for (int i=1;i<N;i++){
        if (v[i].empty()) continue;
        for (auto& x : v[i]) {
            res += findCoprime(i, x.fi, x.se);
        }
    }
    cout << res << '\n';
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    initz();
    cin >> tc;
    while (tc--){
        solve();
    }
 
    return 0;
}