#include<bits/stdc++.h>
using namespace std;


const int N = 1e3+5;
int n,m;
pair<int,int> q[N], p[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int len1 = 0, len2 = 0;
    vector<int> ans(n+3,100000);
    vector<int> cnt(n+3,0);
    vector<int> rcnt(n+3,0);
    for(int i=1;i<=m;i++){
        int t,l,r;cin>>t>>l>>r;
        if(t){
            p[++len1] = {l,r};
            cnt[l+1]++;
            cnt[r+1]--;
        }else{
            q[++len2] = {l,r};
            rcnt[l]++;
            rcnt[r+1]--;
        }
    }

    for(int i=1;i<=n;i++){
        cnt[i] += cnt[i-1];
        rcnt[i] += rcnt[i-1];
    }

    for(int i=1;i<=n;i++){
        if(cnt[i] == 0 && rcnt[i] > 0){
            ans[i] = ans[i-1] - 1;
        }else{
            ans[i] = ans[i-1] + 1;
        }
    }

    bool ok = true;
    for(int i=1;i<=len1;i++){
        for(int j=p[i].first;j<p[i].second;j++){
            ok &= (ans[j] <= ans[j+1]);
        }
    }

    for(int i=1;i<=len2;i++){
        bool good = false;
        for(int j=q[i].first;j<q[i].second;j++){
            good |= (ans[j] > ans[j+1]);
        }
        ok &= good;
    }

    if(!ok){
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << "\n";
    for(int i=1;i<=n;i++){
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
