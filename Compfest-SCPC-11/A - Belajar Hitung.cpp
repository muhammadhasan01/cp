#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+6;
int n;
pair<long long, long long> p[N];

bool compare(pair<long long, long long> a, pair<long long, long long> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

long long f(long long x){
    return x * (x + 1)/2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i].first >> p[i].second;
    }
    long long ans = 0;
    long long l = 0, r = 0;
    sort(p+1,p+1+n,compare);
    for(int i=1;i<=n;i++){
        if(p[i].second > r){
            l = max(r + 1,p[i].first);
            r = p[i].second;
            ans += f(r) - f(l-1);
        }
    }
    cout << ans << '\n';

    return 0;
}
