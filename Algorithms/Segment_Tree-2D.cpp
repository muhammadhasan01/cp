#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://cp-algorithms.com/data_structures/segment_tree.html

const int N = 1024;
int n,tc;
int t[4*N+3][4*N+3];
int a[N+3][N+3];


void build_y(int vx, int sx, int ex, int vy, int sy, int ey){
    if(sy == ey){
        if(sx == ex){
            t[vx][vy] = a[sx][ey];
        }else{
            t[vx][vy] = t[2*vx][vy]+t[2*vx+1][vy];
        }
    }else{
        int my = (sy+ey)/2;
        build_y(vx,sx,ex,2*vy,sy,my);
        build_y(vx,sx,ex,2*vy+1,my+1,ey);
        t[vx][vy] = t[vx][2*vy]+t[vx][2*vy+1];
    }
}

void build_x(int vx, int sx, int ex){
    if(sx != ex){
        int mx = (sx+ex)/2;
        build_x(2*vx,sx,mx);
        build_x(2*vx+1,mx+1,ex);
    }
    build_y(vx,sx,ex,1,1,n);
}

void update_y(int vx, int sx, int ex, int vy, int sy, int ey, int x, int y, int val){
    if(sy == ey){
        if(sx == ex){
            t[vx][vy] = val;
        }else{
            t[vx][vy] = t[2*vx][vy]+t[2*vx+1][vy];
        }
    }else{
        int my = (sy+ey)/2;
        if(y<=my){
            update_y(vx,sx,ex,2*vy,sy,my,x,y,val);
        }else{
            update_y(vx,sx,ex,2*vy+1,my+1,ey,x,y,val);
        }
        t[vx][vy] = t[vx][2*vy]+t[vx][2*vy+1];
    }
}

void update_x(int vx, int sx, int ex, int x, int y, int val){
    if(sx!=ex){
        int mx = (sx+ex)/2;
        if(x <= mx){
            update_x(2*vx,sx,mx,x,y,val);
        }else{
            update_x(2*vx+1,mx+1,ex,x,y,val);
        }
    }
    update_y(vx,sx,ex,1,1,n,x,y,val);
}

int sum_y(int vx, int vy, int sy, int ey, int l, int r){
    //printf("**%d,%d,%d\n",vy,sy,ey);
    if(l > r || vy == 0 || l > ey || r < sy){
        return 0;
    }
    if(l <= sy && ey <= r){
        return t[vx][vy];
    }
    int my = (sy+ey)/2;
    int p1 = sum_y(vx,2*vy,sy,my,l,r);
    int p2 = sum_y(vx,2*vy+1,my+1,ey,l,r);
    return p1+p2;
}

int sum_x(int vx, int sx, int ex, int lx, int rx, int ly, int ry){
    //printf("%d,%d,%d\n",vx,sx,ex);
    if(lx > rx || vx == 0 || ex < lx || rx < sx){
        return 0;
    }
    if(lx <= sx && ex <= rx){
        return sum_y(vx,1,1,n,ly,ry);
    }
    int mx = (sx+ex)/2;
    int p1 = sum_x(2*vx,sx,mx,lx,rx,ly,ry);
    int p2 = sum_x(2*vx+1,mx+1,ex,lx,rx,ly,ry);
    return p1+p2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>tc;
    MEM(t,0);
    while(tc--){
    cin >> n;
    forn(i,n){
        forn(j,n){
            a[i][j] = 0;
        }
    }
    while(true){
        string tt; cin >> tt;
        if(tt == "SET"){
            int x,y,val;
            cin>>x>>y>>val;
            update_x(1,1,n,x,y,val);
        }else if(tt == "SUM"){
            int lx,rx,ly,ry;
            cin >> lx >> ly >> rx >> ry;
            cout << sum_x(1,1,n,lx,rx,ly,ry) << "\n";
        }else if(tt == "END"){
            break;
        }
    }
    }
    return 0;
}
