#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int x;
map<ll,bool> m;

string bin(ll x){
    if(x == 0)return "0";
    if(x == 1)return "1";
    return bin(x/2) + bin(x%2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll mx = 2;
    for(int i=1;i<=32;i++){
        m[mx-1] = 1;
        mx *= 2;
    }

    cin >> x;
    cerr << bin(x) << "\n";
    vector<int> ans;
    int cnt = 0;
    while(m[x] == 0){
        string s = bin(x);
        int n = len(s), pos = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                pos = i;
                break;
            }
        }
        n -= pos;
        int k = (1<<n) - 1;
        //cerr << n << " => " << k << "\n";
        ans.pb(n);
        cnt++;
        x ^= k;
        //cerr << x << "\n";
        if(m[x] == 1)break;
        else{
            x++;
            cnt++;
        }
    }

    cout << cnt << "\n";
    for(auto e:ans)cout << e <<" ";


    return 0;
}
