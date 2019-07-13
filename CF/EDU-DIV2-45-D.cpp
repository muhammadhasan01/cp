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

const int N = 1e3+5;
int n,a,b;
bool ans[N][N];

void answer(int x){
    /* b = 2
    forn(i,2,n){
        a[1][i] = 1;
        a[i][1] = 1;
    }
    // b = 3
    forn(i,3,n){
        a[2][i] = 1;
        a[i][2] = 1;
    }
    // b = 4
    forn(i,4,n){
        a[3][i] = 1;
        a[i][3] = 1;
    }*/

    forn(i,2,x){
        forn(j,i,n){
            ans[i-1][j] = 1;
            ans[j][i-1] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;

    if(n == 1 && a == 1 && b == 1){
        cout << "YES\n"; cout << "0\n"; ex;
    }

    if(n > 3 && a == 1 && b == 1){
        cout << "YES\n";
        forn(i,1,n){
            forn(j,1,n){
                if(abs(i-j) == 1){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }cout << "\n";
        }
    }else if(a == 1 && b > 1){
        answer(b);
        cout << "YES" << "\n";
        forn(i,1,n){
            forn(j,1,n){
                cout << ans[i][j];
            }cout<<"\n";
        }
    }else if(b == 1 && a > 1){
        answer(a);
        cout << "YES" << "\n";
        forn(i,1,n){
            forn(j,1,n){
                if(i == j){
                    cout << 0;
                }else{
                    cout << !(ans[i][j]);
                }
            }cout << "\n";
        }
    }else{
        puts("NO");
    }




    return 0;
}
