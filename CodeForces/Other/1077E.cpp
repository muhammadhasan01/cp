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
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int n;
ll a[200003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n)cin >> a[i];
    sort(a+1,a+1+n);
    if(n == 1){
        cout << 1 << "\n"; return 0;
    }
    deque<int> v;
    int cnt = 1;
    ll last = a[1];
    forn(i,2,n){
        if(last == a[i]){
            cnt++;
            if(i == n)v.pb(cnt);
        }else{
            last = a[i];
            v.pb(cnt);
            cnt = 1;
        }
        //cout << i << " =>" << cnt << "\n";
    }

    sort(all(v));

    int ans = -inf;
    for(int i=1;i<=v.back();i++){
        int sum = 0, now = i, pre = 0;
        while(1){
            auto it = lower_bound(v.begin()+pre,v.end(),now);
            if(it == v.end())break;
            sum += now;
            now *= 2;
            pre = it-v.begin()+1;
        }
        ans = max(ans,sum);
    }

    cout << ans << "\n";

    return 0;
}
