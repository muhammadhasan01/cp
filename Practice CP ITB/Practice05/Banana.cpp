#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(ll i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<ll,ll>
using namespace std;

const ll N = 100;
const ll L = 6;
string t = "BANANA";
ll R,C;
char arr[N+2][N+2];

ll Search(char a[N+2][N+2], string t, ll i, ll j, ll k, ll R, ll C, bool v[N+2][N+2]){
    if(k == L-1){return 0;}
    ll ans = 0;
    if(i+1 <= R && v[i+1][j] != true){
        if(a[i+1][j] == t[k+1]){
            if(k+1 == L-1){ans +=1;}
            v[i+1][j] = true;
            ans += Search(a,t,i+1,j,k+1,R,C,v);
            v[i+1][j] = false;
        }
    }
    if(i+1 <= R && j+1 <= C && v[i+1][j+1] != true){
        if(a[i+1][j+1] == t[k+1]){
            if(k+1 == L-1){ans+=1;}
            v[i+1][j+1] = true;
            ans += Search(a,t,i+1,j+1,k+1,R,C,v);
            v[i+1][j+1] = false;
        }
    }
    if(j+1 <= C && v[i][j+1] != true){
        if(a[i][j+1] == t[k+1]){
            if(k+1 == L-1){ans+=1;}
            v[i][j+1] = true;
            ans += Search(a,t,i,j+1,k+1,R,C,v);
            v[i][j+1] = false;
        }
    }
    if(i-1 >= 1 && v[i-1][j] != true){
        if(a[i-1][j] == t[k+1]){
            if(k+1 == L-1){ans+=1;}
            v[i-1][j] = true;
            ans += Search(a,t,i-1,j,k+1,R,C,v);
            v[i-1][j] = false;
        }
    }
    if(i-1 >= 1 && j-1 >= 1 && v[i-1][j-1] != true){
        if(a[i-1][j-1] == t[k+1]){
            if(k+1 == L-1){ans+=1;}
            v[i-1][j-1] = true;
            ans += Search(a,t,i-1,j-1,k+1,R,C,v);
            v[i-1][j-1] = false;
        }
    }
    if(j-1 >= 1 && v[i][j-1] != true){
        if(a[i][j-1] == t[k+1]){
            if(k+1 == L-1){ans+=1;}
            v[i][j-1] = true;
            ans += Search(a,t,i,j-1,k+1,R,C,v);
            v[i][j-1] = false;
        }
    }
    if(i+1 <= R && j-1 >= 1 && v[i+1][j-1] != true){
        if(a[i+1][j-1] == t[k+1]){
            if(k+1 == L-1){ans+=1;}
            v[i+1][j-1] = true;
            ans += Search(a,t,i+1,j-1,k+1,R,C,v);
            v[i+1][j-1] = false;
        }
    }
    if(i-1 >= 1 && j+1 <= C && v[i-1][j+1] != true){
        if(a[i-1][j+1] == t[k+1]){
            if(k+1 == L-1){ans+=1;}
            v[i-1][j+1] = true;
            ans += Search(a,t,i-1,j+1,k+1,R,C,v);
            v[i-1][j+1] = false;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    for(ll i = 1; i <= R; i++){
        for(ll j = 1; j <= C; j++){
            cin >> arr[i][j];
        }
    }
    bool visit[N+2][N+2]; MEM(visit,false);
    ll ans = 0;
    for(ll i=1;i<=R;i++){
        for(ll j=1;j<=C;j++){
            if(arr[i][j]=='B'){
                visit[i][j] = true;
                ans += Search(arr,t,i,j,0,R,C,visit);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
