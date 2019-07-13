#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 200*1000;
ll n;
pair<ll,ll> a[NMAX+5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(ll i=1;i<=n;i++){cin>>a[i].first; a[i].second = i;}
    sort(a+1,a+n+1);
    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum += a[i].first;
        //cout << a[i].first << " " << a[i].second << "\n";
    }//cout << "\n";
    vector<ll> v;
    for(int i=1;i<=n;i++){
        if(i!=n && sum-a[i].first == 2*a[n].first){
            v.pb(a[i].second);
        }else if(i == n && sum-a[i].first == 2*a[n-1].first){
            v.pb(a[i].second);
        }
    }
    cout << v.size() << "\n";
    for(int i=0;i<v.size();i++){
        cout << v[i];
        if(i != (int)v.size()-1){cout << " ";}
    }
    cout << "\n";
    return 0;
}
