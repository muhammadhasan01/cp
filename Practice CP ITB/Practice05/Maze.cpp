#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define forn(i,n) for(int i=0;i<int(n);i++)
#define ll long long
#define pll pair<long long,long long>
#define pii pair<ll,ll>
using namespace std;

const int N = 100;
int R,C;
string a[N+2];
char b[2*(N+2)][2*(N+2)];
int vis[2*(N+2)][2*(N+2)];
int inc = 0;
char x = char(92);
int mem1,mem2;
bool term = false;

/*
\ => \o
     o\

/ => o/
     /o
*/

void representate(int i, int j){
    if(a[i][j] == '/'){
        i = 2*i, j = 2*j;
        b[i][j] = '*'; b[i+1][j] = '/';
        b[i][j+1] = '/'; b[i+1][j+1] = '*';
    }else if(a[i][j] = x){
        i = 2*i, j = 2*j;
        b[i][j] = x; b[i+1][j] = '*';
        b[i][j+1] = '*'; b[i+1][j+1] = x;
    }
}

void dfs(int i, int j, int vis1, int vis2){
    if(term){return;}
    inc++;
    vis[i][j] = 1;
    int rw[4] = {1,0,-1,0}, cl[4] = {0,1,0,-1};
    for(int k=0;k<4;k++){
    int I = i+rw[k], J = j+cl[k];
    if(0 <= I && I < 2*R && 0 <= J && J < 2*C && b[I][J] == '*'){
        if(I != vis1 | J != vis2){
        if(vis[I][J] == 0){
            dfs(I,J,i,j);
        }else if(vis[I][J] == 1 && !term && (I != vis1 | J != vis2)){
            term = true;
        }}
    }}
    if(i+1 < 2*R && j+1 < 2*C && b[i+1][j] == x && b[i][j+1] == x){
        if(i+1 != vis1 | j+1 != vis2){
        if(vis[i+1][j+1] == 0){
            dfs(i+1,j+1,i,j);}
        else if(vis[i+1][j+1] == 1 && !term){
                term = true;}}
    }
    if(i+1 < 2*R && j-1 >= 0 && b[i+1][j] == '/' && b[i][j-1] == '/'){
        if(i+1 != vis1 | j-1 != vis2){
        if(vis[i+1][j-1] == 0){
            dfs(i+1,j-1,i,j);}
        else if(vis[i+1][j-1] == 1 && !term){
                term = true;}}
    }
    if(i-1 >= 0 && j+1 < 2*C && b[i-1][j] == '/' && b[i][j+1] == '/'){
        if(i-1 != vis1 | j+1 != vis2){
        if(vis[i-1][j+1] == 0){
            dfs(i-1,j+1,i,j);}
        else if(vis[i-1][j+1] == 1 && !term){
                term = true;}}
    }
    if(i-1 >= 0 && j-1 >= 0 && b[i-1][j] == x && b[i][j-1] == x){
        if(i-1 != vis1 | j-1 != vis2){
        if(vis[i-1][j-1] == 0){
            dfs(i-1,j-1,i,j);}
        else if(vis[i-1][j-1] == 1 && !term){
        term = true;}}
    }
    vis[i][j] = 2;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for(int i=0;i<R;i++){
        cin >> a[i];
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            representate(i,j);
        }
    }
    MEM(vis,0);
    int ans = 0, cnt = 0;
    for(int i=0;i<2*R;i++){
        for(int j=0;j<2*C;j++){
                //cout << b[i][j];
            if(b[i][j] == '*' && vis[i][j] == 0){
                dfs(i,j,i,j);
                if(term){ans=max(ans,inc); cnt++;}
                term = false;
                inc = 0;
            }
        }
    }
    cout << cnt << " " << ans << "\n";
    return 0;
}
