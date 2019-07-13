#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define rofn(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n,a,b;
int c[23];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    forn(i,1,n)cin>>c[i];
    int cost = 0;
    forn(i,1,n/2){
        if(c[i] == c[n+1-i]){
            if(c[i] == 1 || c[i] == 0){
                continue;
            }else if(c[i] == 2){
                cost += 2*min(a,b);
            }
        }else{
            if(c[i] == 1 && c[n+1-i] == 0){
                cout << "-1\n"; return 0;
            }else if(c[i] == 0 && c[n+1-i] == 1){
                cout << "-1\n"; return 0;
            }else if(c[i] == 0 && c[n+1-i] == 2){
                cost += a;
            }else if(c[i] == 1 && c[n+1-i] == 2){
                cost += b;
            }else if(c[i] == 2 && c[n+1-i] == 0){
                cost += a;
            }else if(c[i] == 2 && c[n+1-i] == 1){
                cost += b;
            }
        }
    }

    if(n&1){
        if(c[n/2+1] == 2){
            cost += min(a,b);
        }
    }

    cout << cost << "\n";

    return 0;
}
