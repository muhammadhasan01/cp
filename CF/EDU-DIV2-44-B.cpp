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

const int N = 2e3+5;
int n,m;
string a[N];
int f[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,n){
        cin >> a[i];
    }

    forn(i,1,m){
        forn(j,1,n){
            if(a[j][i-1] == '1')f[i-1]++;
        }
    }

    forn(i,1,n){
        bool flag = true;
        forn(j,1,m){
            int m = f[j-1];
            if(a[i][j-1] == '1')m--;
            if(m == 0){
                flag = false; break;
            }
        }
        if(flag){puts("YES"); ex;}
    }

    puts("NO");





    return 0;
}
