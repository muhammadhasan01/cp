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

const int N = (1<<18)+5;
int n, x;
int pre[N];
bitset<N> vis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    int mx = (1<<n) - 1;
    if(x > mx){
        forn(i,1,mx)pre[i] = i;
        cout << mx << "\n";
        forn(i,1,mx){int k = pre[i]^pre[i-1]; cout << k << " ";}
    }else{
        int l = 0;
        forn(i,1,mx){
            if(!vis[i] && i != x){
                int k = i ^ x;
                vis[k] = 1;
                pre[++l] = k;
            }
        }
        cout << l << "\n";
        forn(i,1,l){int k = pre[i]^pre[i-1]; cout << k << " ";}
    }



    return 0;
}
