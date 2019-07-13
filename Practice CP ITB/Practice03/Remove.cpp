#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

bool custom(pll p, pll q){
    return p.second < q.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,temp; cin >> N;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    vector<pll> v;
    for(ll i=0;i<N;i++){cin>>temp;pq.push(make_pair(temp,i));}
    if(N==1){
        cout << "1\n" << temp << "\n";return 0;
    }
    pll t;
    while(!pq.empty()){
        t = pq.top();
        pq.pop();
        if(pq.empty()){v.push_back(t);break;}
        if(t.first == pq.top().first){
            pq.push(make_pair(2*t.first,pq.top().second));
            pq.pop();
        }else{
            v.push_back(t);
        }
    }
    sort(v.begin(),v.end(),custom);
    cout << v.size() << "\n";
    for(ll i=0;i<v.size();i++){
        cout << v[i].first;
        if(i!=v.size()-1){cout<<" ";}else{cout<<"\n";}
    }
    return 0;
}
