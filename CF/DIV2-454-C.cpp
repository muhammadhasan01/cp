#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int n,m;
int a[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> t1(n),t2(m);
    vector<vector<int>> sn(n,t2), sm(m,t1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
            sn[i][j] = a[i][j];
            sm[j][i] = a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        sort(sn[i].begin(),sn[i].end());
        auto it = unique(sn[i].begin(),sn[i].end()) - sn[i].begin();
        sn[i].resize(it);
    }

    for(int i=0;i<m;i++){
        sort(sm[i].begin(),sm[i].end());
        auto it = unique(sm[i].begin(),sm[i].end()) - sm[i].begin();
        sm[i].resize(it);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int p1 = lower_bound(sn[i].begin(),sn[i].end(),a[i][j]) - sn[i].begin();
            int p2 = lower_bound(sm[j].begin(),sm[j].end(),a[i][j]) - sm[j].begin();
            if(p1 > p2){
                cout << max((int)sn[i].size(),(int)sm[j].size() + p1 - p2) << " ";
            }else if(p1 == p2){
                cout << max((int)sn[i].size(),(int)sm[j].size()) << " ";
            }else{
                cout << max((int)sm[j].size(),(int)sn[i].size() + p2 - p1) << " ";
            }
        }cout << '\n';
    }


    return 0;
}
