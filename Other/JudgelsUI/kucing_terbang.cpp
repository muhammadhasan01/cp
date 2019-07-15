#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 1e9+7;
int n;
int a[N];
long long dp[N];
vector<int> bit[N], sum[N];
int maks = -1;

void add(int x, int val){
    for(;x>0;x-=x&-x){
        bit[x].push_back(val);
        sum[x].push_back(0);
    }
}

long long sumQuery(int x, int pos){
    long long ret = 0;
    for(;pos>=0;pos=(pos&(pos+1))-1){
        ret += sum[x][pos];
        ret %= M;
    }
    return ret;
}

int query(int x, int val){
    int ret = 0;
    for(;x<=maks;x+=x&-x){
        int pos = lower_bound(bit[x].begin(),bit[x].end(),val) - bit[x].begin();
        pos--;
        if(pos < 0)continue;
        long long cur = sumQuery(x, pos);
        ret += cur; ret %= M;
    }
    return ret;
}

void addSum(int x, int val, long long sumval){
    for(;x>0;x-=x&-x){
        int pos = lower_bound(bit[x].begin(),bit[x].end(),val) - bit[x].begin();
        if(pos < (int)bit[x].size() && bit[x][pos] == val){
            for(int tpos=pos;tpos<bit[x].size();tpos|=(tpos + 1)){
                sum[x][tpos] += sumval;
                sum[x][tpos] %= M;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maks = max(maks, a[i]);
    }
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        add(a[i],i);
    }
    for(int i=1;i<=n;i++)sort(bit[i].begin(),bit[i].end());
    long long ans = 0;
    for(int i=1;i<=n;i++){
        long long qcur = query(a[i],i);
        dp[i] = (qcur + 1)%M;
        ans = (ans + dp[i])%M;
        addSum(a[i],i,dp[i]);
    }
    cout << (ans%M + M)%M << '\n';

    return 0;
}
