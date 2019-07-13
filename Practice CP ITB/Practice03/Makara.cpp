#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool custom(pair<ll,ll> p, pair<ll,ll> q){
    return p.second > q.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,temp; cin >> N;
    pair<ll,ll> a[N+2];
    ll b[N], c[N], counter; memset(b,0,sizeof(b)); memset(c,0,sizeof(c));
    a[0].first = INT_MAX, a[0].second=0;
    for(ll i=1;i<N+1;i++){cin>>temp;a[i].first = temp; a[i].second = i-1;}
    a[N+1].first = INT_MAX, a[N+1].second=0;
    if(N==1){
        cout << "0\n";return 0;
    }
    stack<pair<ll,ll> > s;
    s.push(a[1]);
    for(ll i=2;i<N+2;i++){
        if(a[i].first < s.top().first){
            s.push(a[i]);
        }else{
            while(a[i].first >= s.top().first && !s.empty()){
                b[s.top().second] = i-s.top().second-2;
                s.pop();
                if(s.empty()){break;}
            }
            s.push(a[i]);
        }
    }
    stack<pair<ll,ll> > s2;
    s2.push(a[N]);
    for(ll i=N-1;i>=0;i--){
        if(a[i].first < s2.top().first){
            s2.push(a[i]);
        }else{
            while(a[i].first >= s2.top().first && !s2.empty()){
                c[s2.top().second] = s2.top().second-i;
                s2.pop();
                if(s2.empty()){break;}
            }
            s2.push(a[i]);
        }
    }
    for(ll i=0;i<N;i++){
        cout << b[i]+c[i];
        if(i!=N){cout<<" ";}else{cout<<"\n";}
    }
    return 0;
}
