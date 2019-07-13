#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int N = 2005;
int tc;
int n,m;
char a[N][N];

pii find(int x, int y, int vw){
    pii k = {0,0};
    for(int i=n;i>=x+1;i--){
        int vwf = a[i][y] - 'a';
        if(vwf == vw){
            k = {i,y};
            break;
        }
    }
    return k;
}

pii find2(int x, int y, int vw){
    pii k = {0,0};
    for(int i=m;i>=y+1;i--){
        int vwf = a[x][i] - 'a';
        if(vwf == vw){
            k = {x,i};
            break;
        }
    }
    return k;
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    vector<pair<pii,pii>> v(27,{{0,0},{0,0}});
    pair<pii,pii> pzero = {{0,0},{0,0}};
    pii zero = {0,0};
    int maxi = -1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] != '.'){
                int vw = a[i][j] - 'a';
                maxi = max(maxi, vw);
                if(v[vw].first == zero){
                    v[vw].first = {i,j};
                    v[vw].second = {i,j};
                    pii k1 = find(i,j,vw);
                    pii k2 = find2(i,j,vw);
                    if(k1 != zero && k2 == zero){
                        v[vw].second = k1;
                    }else if(k1 == zero && k2 != zero){
                        v[vw].second = k2;
                    }else if(k1 != zero && k2 != zero){
                        cout << "NO" << '\n';
                        return;
                    }
                }else if(i != v[vw].first.first && j != v[vw].first.second){
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
    }
    if(maxi == -1){
        cout << "YES" << '\n';
        cout << 0 << '\n';
        return;
    }
    pair<pii,pii> last;
    for(int i=maxi;i>=0;i--){
        if(v[i] == pzero){
            v[i] = last;
        }else{
            last = v[i];
        }
    }
    for(int i=maxi;i>=0;i--){
        pii k1 = v[i].first, k2 = v[i].second;
        if(k1.first == k2.first){
            for(int j=k1.second;j<=k2.second;j++){
                if(a[k1.first][j] != '.'){
                    int vwc = a[k1.first][j] - 'a';
                    if(vwc < i){
                        cout << "NO" << '\n';
                        return;
                    }
                }else{
                    cout << "NO" << '\n';
                    return;
                }
            }
        }else if(k1.second == k2.second){
            for(int j=k1.first;j<=k2.first;j++){
                if(a[j][k1.second] != '.'){
                    int vwc = a[j][k1.second] - 'a';
                    if(vwc < i){
                        cout << "NO" << '\n';
                        return;
                    }
                }else{
                    cout << "NO" << '\n';
                    return;
                }
            }
        }
    }
    cout << "YES" << '\n';
    cout << maxi + 1 << '\n';
    for(int i=0;i<=maxi;i++){
        cout << v[i].first.first << " " << v[i].first.second << " ";
        cout << v[i].second.first << " " << v[i].second.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    for(int nt=1;nt<=tc;nt++){
        solve();
    }


    return 0;
}
