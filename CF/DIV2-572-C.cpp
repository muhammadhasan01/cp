#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n,q;
int s[N];
pair<int,int> pre[25][N];
int store[25];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    store[0] = 1;
    for(int i=1;i<=25;i++)store[i] = store[i-1] * 2;

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> pre[0][i].first;
        pre[0][i].second = 0;
    }

    for(int i=1;i<=20;i++){
        for(int j=1;j<=n-store[i]+1;j++){
            if(j + store[i]/2 > n)break;
            pre[i][j].first = (pre[i-1][j].first + pre[i-1][j + store[i]/2].first)%10;
            pre[i][j].second = pre[i-1][j].second + pre[i-1][j + store[i]/2].second;
            if(pre[i-1][j].first + pre[i-1][j + store[i]/2].first >= 10)pre[i][j].second++;
        }
    }


    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        if(l == r){
            cout << 0 << "\n";
        }else{
            int pos = lower_bound(store,store+24,r-l+1) - store;
            cout << pre[pos][l].second << "\n";
        }
    }


    return 0;
}
