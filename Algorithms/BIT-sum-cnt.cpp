#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/1185/problem/C2
// inspired by : https://codeforces.com/profile/Luqman

const int N = 2e5+5;

int n,m;
int t[N],sum[N], cnt[N], pos[N];

void add(int *bit, int i, int val){
    for(;i<=n;i+=i&-i){
        bit[i] += val;
    }
}

int get(int *bit, int i){
    int ret = 0;
    for(;i>0;i-=i&-i){
        ret += bit[i];
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<pair<int,int>> p(n+1);
    for(int i=1;i<=n;i++){
        cin >> t[i];
        p[i] = {t[i],i};
    }
    sort(p.begin()+1,p.begin()+1+n);
    for(int i=1;i<=n;i++){
        pos[p[i].second] = i;
    }
    for(int i=1;i<=n;i++){
        int req = m - t[i];
        int l = 0, r = n, ans;
        while(l<=r){
            int mid = (l+r)>>1;
            if(get(sum,mid) <= req){
                l = mid+1;
                ans = mid;
            }else{
                r = mid-1;
            }
        }
        cout << i - get(cnt,ans) - 1 << " ";
        add(sum,pos[i],t[i]);
        add(cnt,pos[i],1);
    }

    return 0;
}
