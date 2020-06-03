// author : Mastre
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

const int N = 1e5 + 10;
const int M = 300;

int n;
string s;

vector<int> fac;
int gcdCnt[N];

bool bisa[N];
int ans;
int pre[N * 2][M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    // cout << s << " " << n << el;
    fac.pb(1);
    for (int i=2;i * i<=n;i++){
        if (n % i == 0){
            int j = n / i;
            fac.pb(i);
            if (i != j) fac.pb(j);
        }
    }
    sort(fac.begin(), fac.end());
    // for (auto x : fac){
    //     cout << x << " ";
    // }
    // cout << el;
    for (int i=1;i<n;i++){
        int gcc = __gcd(i, n);
        gcdCnt[gcc]++;
    }
    
    int nfac = fac.size();
    for (int i=1;i<=n + n;i++){
        int id = i;
        if (id > n) id -= n;
        int dig = s[id - 1] == 'P';
        for (int j=0;j<nfac;j++){
            int bef = max(0, i - fac[j]);
            pre[i][j] = pre[bef][j] + dig;
        }
    }
    
    for (int i=1;i<=n;i++){
        int ni = i + n;
        for (int j=0;j<nfac;j++){
            if (pre[ni][j] - pre[i][j] == 0){
                bisa[fac[j]] = 1;
            }
        }
    }
    for (int i=1;i<n;i++) {if (bisa[i]) ans += gcdCnt[i];}
    cout << ans << el;

    return 0;
}