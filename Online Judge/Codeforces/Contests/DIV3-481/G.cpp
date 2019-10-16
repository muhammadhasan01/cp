#include<bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> pii;

const int N = 105;

struct st{
    int s,d,c;
};

int n,m;
st a[N];
bitset<N> vis;
int ans[N];
vector<pii> v[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a[i].s >> a[i].d >> a[i].c;
        vis[a[i].d] = 1;
        v[a[i].s].push_back({{a[i].d, a[i].c},i});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i=1;i<=n;i++){

        for(auto e:v[i]){
            pq.push(e);
        }

        if(vis[i]){
            ans[i] = m + 1;
        }else{
            if(pq.empty()){
                ans[i] = 0;
            }else{
                pii x = pq.top();
                pq.pop();
                ans[i] = x.second;
                if(--x.first.second > 0){
                    pq.push(x);
                }
            }
        }
    }

    bool valid = true;
    for(int i=1;i<=m;i++){
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(a[i].s <= j && j < a[i].d && ans[j] == i){
                cnt++;
            }
        }
        valid &= (cnt == a[i].c);
        if(!valid)break;
    }

    if(valid){
        for(int i=1;i<=n;i++){
            cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }else{
        cout << -1 << '\n';
    }



    return 0;
}
