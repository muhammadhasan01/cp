#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, B, C, jawab = 0, temp;
    cin >> N >> B >> C;
    vector<ll> a; vector<ll>::iterator p,q;
    for(ll i = 0; i < N; i++){cin >> temp; a.push_back(temp);}
    sort(a.begin(),a.end());
    ll near,cek,cek2;
    for(ll i=0;i<N;i++){
        if(a[i]%B!=0){near = a[i]+B-a[i]%B;}else{near = a[i];}
        q = lower_bound(a.begin(),a.end(),near+B*(C-1));
        p = lower_bound(a.begin(),a.end(),near+B*C)-1;
        if(q==a.end())q--;
        cek2= *q/B-a[i]/B;if(a[i]%B==0){cek2++;}
        cek = *p/B-a[i]/B;if(a[i]%B==0){cek++;}
        if(cek == C && cek2 == C){jawab+=p-q+1;}
    }
    cout << jawab << "\n";
    return 0;
}
