#include<bits/stdc++.h>
using namespace std;

struct st{
    int h,w,idx;
};

st make(int a, int b, int c){
    st temp;
    temp.h = a, temp.w = b, temp.idx = c;
    return temp;
}

bool cstm(st a, st b){
    if(a.h == b.h){
        return a.w < b.w;
    }
    return a.h < b.h;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,h,w;
    cin >> n >> h >> w;
    vector<st> a;

    for(int i=1;i<=n;i++){
        int x,y;
        cin >> x >> y;
        if(x > h && y > w){
            a.push_back(make(x,y,i));
        }
    }

    if(a.size() == 0){
        cout << 0 << '\n';
        return 0;
    }

    sort(a.begin(),a.end(),cstm);

    int len = a.size();
    vector<int> dp(len+3,0);
    int ans = 0, pos = 0;
    vector<int> par(len+3,0);
    iota(par.begin(),par.end(),0);

    for(int i=0;i<len;i++){
        dp[i] = 1;
        for(int j=i-1;j>=0;j--){
            if(a[i].h > a[j].h & a[i].w > a[j].w && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                par[i] = j;
            }
        }
        if(dp[i] > ans){
            ans = dp[i];
            pos = i;
        }
    }

    deque<int> oc;
    for(int i=pos;;i=par[i]){
        oc.push_front(a[i].idx);
        if(i == par[i])break;
    }

    cout << oc.size() << '\n';
    for(auto e:oc)cout << e << " ";

    return 0;
}
