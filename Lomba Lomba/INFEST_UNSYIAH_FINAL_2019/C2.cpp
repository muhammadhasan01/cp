#include<bits/stdc++.h>
using namespace std;
bool __cmp(int a,int b){
    return a>=b;
}
int helper(int curr,int idx,vector<bool>&visit,int len,map<int,int>&mp,vector<int>&cp){
    if(visit[idx])
        return len-1;
    visit[idx]=true;
    return helper(cp[mp[curr]],mp[curr],visit,len+1,mp,cp);
}
int ctSwp(int n,vector<int>&arr,vector<int>&cp,int ans=0){
    map<int,int> mp; for(int i=0;i<n;i++) mp[arr[i]]=i;
    vector<bool> visit(n,false);
    for(int i=0;i<n;i++)
        if(visit[i]==false)
            ans+=helper(cp[i],i,visit,0,mp,cp);
    return ans;
}
int main() {
    int n; cin >> n;
    vector<int> arr(n); for (int i=0;i<n;i++) cin >> arr[i];
    vector<int> inc(arr);sort(inc.begin(),inc.end());
    vector<int> dec(arr);sort(dec.begin(),dec.end(),__cmp);
    cout << min(ctSwp(n,arr,inc),ctSwp(n,arr,dec)) << endl;
    return 0;
}
