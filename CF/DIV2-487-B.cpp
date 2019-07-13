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

int n,p;
string a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p >> a;
    if(p == n){
        puts("No"); ex;
    }
    bool ok = false;
    for(int i=0;i<p;i++){
        if(a[i] != '.'){
            for(int j=i+p;j<=n-1;j+=p){
                if(a[i] != a[j]){
                    ok = true;
                    if(a[j] == '.'){
                        if(a[i] == '1')a[j] = '0';
                        else a[j] = '1';
                    }
                }
            }
        }else{
            a[i] = '1';
            for(int j=i+p;j<=n-1;j+=p){
                if(a[i] != a[j]){
                    ok = true;
                    a[j] = '0';
                }
            }

            if(!ok){
                a[i] = '0';
                for(int j=i+p;j<=n-1;j+=p){
                    if(a[i] != a[j]){
                        ok = true;
                        a[j] = '1';
                    }
                }
            }
        }
    }

    cout << (ok ? a : "No") << "\n";





    return 0;
}
