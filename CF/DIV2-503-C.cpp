#include<bits/stdc++.h>
using namespace std;

const int N = 3e3+5;
int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<pair<long long,int>> p;
    vector<int> f(m+5,0);
    for(int i=1;i<=n;i++){
        int x; long long y;
        cin >> x >> y;
        if(x > 1)p.push_back({y,x});
        f[x]++;
    }

    sort(p.rbegin(), p.rend());

    long long ans = 1e18;
    for(int i=1;i<=n;i++){
        vector<pair<long long, int>> v = p;
        vector<long long> rem;
        vector<int> fn = f;
        long long sum = 0;
        while(!v.empty()){
            long long x = v.back().first;
            int y = v.back().second;
            v.pop_back();
            if(fn[y] >= i){
                fn[y]--;
                fn[1]++;
                sum += x;
            }else{
                rem.push_back(x);
            }
        }
        if(fn[1] >= i){
            ans = min(ans, sum);
        }else{
            for(auto e:rem){
                fn[1]++;
                sum += e;
                if(fn[1]>=i)break;
            }
            ans = min(ans,sum);
        }
    }

    cout << ans << "\n";

    return 0;
}
