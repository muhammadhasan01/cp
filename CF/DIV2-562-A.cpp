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

int n,a,x,b,y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> x >> b >> y;
    while(true){
        if(a != x){
            a++;
        }
        if(b != y){
            b--;
        }
        if(a > n)a = 1;
        if(b < 1)b = n;
        if(a == b){
            puts("YES"); ex;
        }
        if(a == x || b == y)break;
    }


    puts("NO");




    return 0;
}
