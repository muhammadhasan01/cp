// Author: Micchon
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>

const int MOD = 1000000007;
//const int MOD = 998244353;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n; cin >> n;
    vector<pair<int,int>> vec(n); forn(i,n) cin >> vec[i].first >> vec[i].second;
    forn(i,n){
        assert(vec[i].second >= 0);
    }
    vec.emplace_back(0,0);
    sort(vec.begin(),vec.end(),greater<pair<int,int>>());
    int time = vec[0].first;
    priority_queue<int> pq;
    int ans = 0;
    forn(i,vec.size()){
        int jml = time - vec[i].first;
        while(!pq.empty())
        {
            if(!jml) break;
            jml--;
            ans += pq.top(); pq.pop();
        }
        time = vec[i].first;
        pq.push(vec[i].second);
    }
    cout << ans << '\n';
    return 0;
}
