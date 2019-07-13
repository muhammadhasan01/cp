#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool custom(pair<ll,ll> p,pair<ll,ll> q){
    return p.second > q.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,A,B,t1,t2;cin>>N>>A>>B;
    string t3;
    vector<pair<ll,ll> > male,female;
    for(int i=0;i<N;i++){
        cin >> t1 >> t2 >> t3;
        if(t3 == "M"){male.push_back(make_pair(t2,t1));}
        else{female.push_back(make_pair(t2,t1));}
    }
    sort(male.rbegin(),male.rend(),custom); sort(female.rbegin(),female.rend(),custom);
    cout <<"\n";
    for(int i=0;i<male.size();i++){cout<<male[i].first<<" "<<male[i].second<<"\n";}cout<<"\n";
    for(int i=0;i<female.size();i++){cout<<female[i].first<<" "<<female[i].second<<"\n";}
    cout << "\n";
    return 0;
}
