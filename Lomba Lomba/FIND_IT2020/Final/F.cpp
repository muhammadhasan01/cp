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
 
const int N = 1e3 + 10;
 
int q;
int n;
int ar[N];
int cnt = 0, hmm;
 
void solve(){
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (ar[i] == i) continue;
        int pos = -1;
        for (int j=i + 1;j<=n;j++){
            if (ar[j] == i){
                pos = j;
                break;
            }
        }
        ans++;
        swap(ar[i], ar[pos]);
    }
    cout << ans;
    if (cnt < hmm) cout << el;
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> q;
    hmm = q;
    while (q--) {
        ++cnt;
        solve();
    }
 
    return 0;
}