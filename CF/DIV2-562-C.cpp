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

const int N = 3e5+5;
int n,m;
int a[N];

bool can(int k){
    int last = 0;
    forn(i,1,n){
        if(last - a[i] > k)return false;
        if(a[i]>=last){
            if((a[i]+k)<m || (a[i]+k)%m < last)last = a[i];
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,n)cin >> a[i];
    int l = 0, r = m-1, ans;
    while(l <= r){
        int m = (l+r)/2;
        if(can(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout << ans << "\n";





    return 0;
}
