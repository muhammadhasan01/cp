#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// Finding maximal intersection

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, temp1, temp2, fin; cin >> n;
    pair<ll,ll> a[n];
    for(ll i=0;i<n;i++){
      cin >> a[i].first >> a[i].second;
    }
    sort(a,a+n, greater<pair<ll,ll> >());
    ll its = 0, nits = 0, best = a[0].first, mini =a[0].second, index1 = 0, index2 = 0, index3 = 0, index4 = 0;
    ll best2 = best;
    for(ll i = 0; i < n-1; i++){
        if(a[i].second < mini){
            mini = a[i].second;
            index2 = i;
        }
        if(a[i].first == best)index1 = i;
        if(a[i].first > a[i+1].second){
        nits++;
        index3 = i, index4 = i+1;
        if(nits == 2){cout << "0\n";return 0;}
      }else{its++;}
    }
    if(a[n-1].second < mini){mini = a[n-1].second; index2 = n-1;}
    if(a[n-1].first == best)index1 = n-1;
    if(nits==0){
        ll ans1, ans2;
        ll temp1 = -1, temp2 = inf;
        for(ll i=0;i<n;i++){
            if(i != index1 && a[i].first > temp1){
                temp1 = a[i].first;
            }
            if(i != index1 && a[i].second < temp2){
                temp2 = a[i].second;
            }
        }
        ans1  = temp2-temp1;
        temp1 = -1, temp2 = inf;
        for(ll i=0;i<n;i++){
            if(i!=index2 && a[i].first > temp1){
                temp1 = a[i].first;
            }
            if(i!=index2 && a[i].second < temp2){
                temp2 = a[i].second;
            }
        }
        ans2 = temp2-temp1;
        fin = max(ans1,ans2);
        if(fin<0){cout << "0\n";}else{cout << fin << el;}
    }else if(nits == 1){
        ll ans3, ans4;
        ll temp3 = -1, temp4 = inf;
        for(ll i=0;i<n;i++){
            if(i!=index3 && a[i].first > temp3){
                temp3 = a[i].first;
            }
            if(i!=index3 && a[i].se < temp4){
                temp4 = a[i].second;
            }
        }
        ans3 = temp4-temp3;
        temp3 = -1, temp4  = inf;
        for(ll i=0;i<n;i++){
            if(i!=index4 && a[i].first > temp3){
                temp3 = a[i].first;
            }
            if(i!=index4 && a[i].se < temp4){
                temp4 = a[i].second;
            }
        }
        ans4 = temp4-temp3;
        fin = max(ans3,ans4);
        if(fin < 0){cout << "0\n";}else{cout << fin << el;}
    }
    return 0;
}

