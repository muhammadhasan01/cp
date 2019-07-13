#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n,m;
char a[N][N];
int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] = {1,-1,0,0,-1,1,1,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == '.')a[i][j] = '0';
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if('0' <= a[i][j] && a[i][j] <= '8'){
                int k = a[i][j] - '0';
                int cnt = 0;
                for(int t = 0; t < 8; t++){
                    int tx = i + dx[t];
                    int ty = j + dy[t];
                    if(1 <= tx && tx <= n && 1 <= ty && ty <= m){
                        if(a[tx][ty] == '*')cnt++;
                    }
                }
                if(cnt != k){
                    puts("NO");
                    return 0;
                }
            }
        }
    }

    puts("YES");


    return 0;
}
