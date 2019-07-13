#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int n,m,k;
char a[N][N];
bool vis[N][N];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
stack<pair<int,int>> st;

void dfs(int x, int y){
    st.push({x,y});
    vis[x][y] = 1;
    //cerr << x << " " << y << '\n';
    for(int i=0;i<4;i++){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(cx < 1 || cx > n)continue;
        if(cy < 1 || cy > m)continue;
        if(vis[cx][cy])continue;
        dfs(cx,cy);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == '#')vis[i][j] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]){
                dfs(i,j);
                break;
            }
        }
    }

    int cnt = 0;
    while(cnt < k && !st.empty()){
        pair<int,int> temp = st.top();
        st.pop();
        a[temp.first][temp.second] = 'X';
        cnt++;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << a[i][j];
        }cout << '\n';
    }


    return 0;
}
