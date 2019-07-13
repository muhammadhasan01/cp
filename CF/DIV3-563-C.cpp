#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 5e5+10;
int n;
int a[N];
vector<int> v = {4,8,15,16,23,42};
int f[7][N];
int ok,p1,p2,p3,p4,p5,p6;
int id[10],pos[10];

void check(int x){

    int len;
    if(x == 1)len = p2;
    else if(x == 2)len = p3;
    else if(x == 3)len = p4;
    else if(x == 4)len = p5;
    else if(x == 5)len = p6;

    int k = id[x];
    for(int i=k;i<len;i++){
        id[x] = i+1;
        if(f[x][i] > pos[x-1]){
            pos[x] = f[x][i];
            if(x < 5){
                check(x+1);
                return;
            }else if(x == 5){
                ok += 6;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        int x; cin >> x;
        if(x == v[0]){
            f[0][p1++] = i;
        }else if(x == v[1]){
            f[1][p2++] = i;
        }else if(x == v[2]){
            f[2][p3++] = i;
        }else if(x == v[3]){
            f[3][p4++] = i;
        }else if(x == v[4]){
            f[4][p5++] = i;
        }else if(x == v[5]){
            f[5][p6++] = i;
        }
    }

    for(int i=0;i<p1;i++){
        pos[0] = f[0][i];
        check(1);
    }

    cout << n - ok << "\n";


    return 0;
}
