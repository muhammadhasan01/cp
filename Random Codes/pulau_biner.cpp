#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int n;
char a[N][N];
int dist[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            dist[i][j] = (int)1e9;
        }
    }

    deque<pair<int,int>> q;
    q.push_front({1,1});
    dist[1][1] = 0;
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop_front();
        for(int i=0;i<4;i++){
            int curx = temp.first + dx[i];
            int cury = temp.second + dy[i];
            if(curx < 1 || curx > n)continue;
            if(cury < 1 || cury > n)continue;
            int res = (a[curx][cury] == '1' ? 1 : 0);
            if(dist[curx][cury] > dist[temp.first][temp.second] + res){
                dist[curx][cury] = dist[temp.first][temp.second] + res;
                if(res == 0)
                q.push_front({curx,cury});
                else q.push_back({curx,cury});
            }
        }
    }
    cout << dist[n][n] << '\n';


    return 0;
}
