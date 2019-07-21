#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
vector<int> bit[N];
int tc,n,a[N];

void add(int x, int val){
    for(;x<=n;x+=x&-x)bit[x].push_back(val);
}

long long query(int x, int val){
    int ret = 0;
    for(;x>0;x-=x&-x){
        int l = 0, r = bit[x].size() - 1, ans = 0;
        while(l <= r){
            int mid = (l+r)>>1;
            if(bit[x][mid] > val){
                l = mid + 1;
                ans = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        ret += ans;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++)bit[i].clear();
        for(int i=1;i<=n;i++){
            cin >> a[i];
            add(i,a[i]);
        }
        for(int i=1;i<=n;i++)sort(bit[i].begin(),bit[i].end(),greater<int>());
        long long res = 0;
        for(int i=1;i<=n;i++){
            res += query(i-1,a[i]);
        }
        cout << res << '\n';
    }


    return 0;
}
