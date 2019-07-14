#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 1e9+7;
int n;
int a[N];
vector<pair<int,int>> bit[N];
long long dp[N];

void add(int x, int val, int pos){
    for(;x<=n;x+=x&-x){
        bit[x].push_back({val,pos});
    }
}

int query(int x, int val){
    int ret = -1;
    for(;x>0;x-=x&-x){
        int l = 0, r = bit[x].size()-1, pos = -1;
        while(l <= r){
            int mid = (l+r)>>1;
            if(bit[x][mid].first >= val){
                r = mid - 1;
                pos = bit[x][mid].second;
            }else{
                l = mid + 1;
            }
        }
        ret = max(ret, pos);
    }
    return ret;
}

bool cmpr(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        add(i,a[i],i);
    }
    for(int i=1;i<=n;i++)sort(bit[i].begin(),bit[i].end(),cmpr);
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        int pos = query(i-1,a[i]);
        dp[i] = dp[i-1] + (pos == -1 ? 0 : dp[pos]) + 1;
        dp[i] %= M;
    }
    cout << (dp[n]%M + M)%M << "\n";

    return 0;
}
