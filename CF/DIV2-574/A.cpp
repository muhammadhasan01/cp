#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[1003];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    int m = (n+1)/2;
    vector<int> cnt(k+3,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];cnt[a[i]]++;
    }
    vector<int> cnt2(k+3,0);
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=k;i++){
        if(cnt[i] != 0){
            pq.push({cnt[i],i});
        }
    }
    int cntt = 0;
    while(!pq.empty() && cntt < m){
        int cur = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(cur - 2 > 0){
            pq.push({cur-2,x});
        }
        cnt2[x] += 2;
        cntt++;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(cnt2[a[i]] > 0){
            ans++;
            cnt2[a[i]]--;
        }
    }
    cout << ans << '\n';

    return 0;
}
