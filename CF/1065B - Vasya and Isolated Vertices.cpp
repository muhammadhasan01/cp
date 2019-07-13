#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define first fs
#define second sc
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// Vasya and Isolated Vertices

ll precomp(ll m){
    if(m==1)return 2;
    if(m==2)return 3;
    if(m==3)return 3;
    ld x = sqrt(1+8*m);
    ll y = x;
    ll ans = (1+x)/2+1;
    if(x==y){ans--;}
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m; cin >> n >> m;
    if(n==1){
        cout << "1 1\n";
    }else{
        if(m==0){cout << n << " " << n << "\n";}
        else if(m==1){cout << n-2 << " " << n-2 << "\n";}
        else{
            ll mini, maxi;
            mini = n-2*m; if(mini<0){mini=0;}
            maxi = n-precomp(m);if(maxi<0){maxi = 0;}
            cout << mini << " " << maxi << "\n";
        }
    }
    return 0;
}
