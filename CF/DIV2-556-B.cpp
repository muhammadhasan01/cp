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

const int N = 55;
int n;
char a[N][N];

bool can(int x, int y){
    if(a[x+1][y] == '.' && a[x-1][y] == '.' && a[x][y+1] == '.' && a[x][y-1] == '.'){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        forn(j,1,n){
            cin >> a[i][j];
        }
    }

    bool ok = false;
    forn(i,2,n-1){
        forn(j,2,n-1){
            if(a[i][j] == '.'){
                if(can(i,j)){
                    ok = true;
                    a[i][j] = '#';
                    a[i+1][j] = '#';
                    a[i-1][j] = '#';
                    a[i][j+1] = '#';
                    a[i][j-1] = '#';
                }
            }
        }
    }

    bool flag = true;
    forn(i,1,n){
        forn(j,1,n){
            if(a[i][j] == '.'){
                flag = false;
                break;
            }
        }
    }

    if(flag && ok){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

    return 0;
}
