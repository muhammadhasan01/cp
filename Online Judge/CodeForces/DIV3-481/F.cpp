#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n,k;
pair<int,int> r[N];
int par[N];
int ans[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> r[i].first;
        r[i].second = i;
    }

    sort(r+1,r+1+n);

    for(int i=1;i<=n;i++){
        int le = 1, ri = i, res = 0;
        while(le <= ri){
            int mid = (le+ri)>>1;
            if(r[mid].first < r[i].first){
                le = mid + 1;
                res = mid;
            }else{
                ri = mid - 1;
            }
        }
        ans[r[i].second] = res;
        par[r[i].second] = r[i].first;
    }

    for(int i=1;i<=k;i++){
        int x,y;
        cin >> x >> y;
        if(par[x] > par[y]){
            ans[x]--;
        }else if(par[x] < par[y]){
            ans[y]--;
        }
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << (i == n ? '\n' : ' ');
    }


    return 0;
}
