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

const int N = 53;
int n,m;
int a[N][N], b[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    forn(i,1,n){
        forn(j,1,m){
            cin >> a[i][j];
        }
    }


    forn(i,1,n){
        forn(j,1,m){
            cin >> b[i][j];
        }
    }

    forn(i,1,n){
        forn(j,1,m-1){
            if(a[i][j] >= a[i][j+1]){
                if(b[i][j] >= a[i][j+1]){
                    cout << "Impossible" << '\n';
                    ex;
                }else{
                    if(a[i][j] >= b[i][j+1]){
                        cout << "Impossible" << '\n';
                        ex;
                    }
                    swap(a[i][j],b[i][j]);
                }
            }
        }
    }

    forn(i,1,n){
        forn(j,1,m-1){
            if(b[i][j] >= b[i][j+1]){
                if(a[i][j] >= b[i][j+1]){
                    cout << "Impossible" << '\n';
                    ex;
                }else{
                    if(b[i][j] >= a[i][j+1]){
                        cout << "Impossible" << '\n';
                        ex;
                    }
                    swap(a[i][j],b[i][j]);
                }
            }
        }
    }

    forn(i,1,m){
        forn(j,1,n-1){
            if(a[j][i] >= a[j+1][i]){
                if(b[j][i] >= a[j+1][i]){
                    cout << "Impossible" << '\n';
                    ex;
                }else{
                    if(a[j][i] >= b[j+1][i]){
                        cout << "Impossible" << '\n';
                        ex;
                    }
                    swap(a[j][i], b[j][i]);
                }
            }
        }
    }

    forn(i,1,m){
        forn(j,1,n-1){
            if(b[j][i] >= b[j+1][i]){
                if(a[j][i] >= b[j+1][i]){
                    cout << "Impossible" << '\n';
                    ex;
                }else{
                    if(b[j][i] >= a[j+1][i]){
                        cout << "Impossible" << "\n";
                        ex;
                    }
                    swap(a[j][i], b[j][i]);
                }
            }
        }
    }


    cout << "Possible\n";


    return 0;
}
