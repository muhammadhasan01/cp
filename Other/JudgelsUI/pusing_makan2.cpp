#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 1e9+7;
int n;
pair<int,int> p[N];
long long dp[N];

bool cstm(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> p[i].first >> p[i].second;
    }

    sort(p+1,p+1+n,cstm);

    for(int i=1;i<=n;i++){
        int l = 1, r = i-1, pos = 0;
        while(l <= r){
            int mid = (l+r)>>1;
            if(p[mid].second < p[i].first){
                l = mid + 1;
                pos = mid;
            }else{
                r = mid - 1;
            }
        }
        dp[i] = dp[i-1] + 1 + dp[pos];
        dp[i] %= M;
    }
    cout << (dp[n]%M + M)%M << "\n";


    return 0;
}
