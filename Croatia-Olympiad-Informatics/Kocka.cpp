#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int NMAX = 100*1000;
int n;
int le[NMAX+2];
int ri[NMAX+2];
int to[NMAX+2];
int bo[NMAX+2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=4;i++){
        for(int j=1; j<=n; j++){
            if(i == 1){
                cin >> le[j];
            }else if(i == 2){
                cin >> ri[j];
            }else if(i == 3){
                cin >> to[j];
            }else if(i == 4){
                cin >> bo[j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        if((le[i] == -1 && ri[i] != -1) || ri[i]+le[i] > n-1){
            cout << "NE\n"; return 0;
        }else if(le[i]!=-1){
            if((to[le[i]+1] > i-1) || (bo[le[i]+1] > n-i)){
                cout << "NE\n"; return 0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if((ri[i] == -1 && le[i] != -1) || ri[i]+le[i] > n-1){
            cout << "NE\n"; return 0;
        }else if(ri[i]!=-1){
            if((to[n-ri[i]] > i-1) || (bo[n-ri[i]] > n-i)){
                cout << "NE\n"; return 0;
            }
        }
    }

    for(int i=1;i<=n;i++){
        if((to[i] == -1 && bo[i] != -1) || bo[i]+to[i] > n-1){
            cout << "NE\n"; return 0;
        }
    }

    for(int i=1;i<=n;i++){
        if((bo[i] == -1 && to[i] != -1) || bo[i]+to[i] > n-1){
            cout << "NE\n"; return 0;
        }
    }
    cout << "DA\n";
    //cout << "\n";
    //for(int i=1;i<=n;i++){
    //    for(int j=1;j<=n;j++){
    //        cout << x[i][j] << " ";
    //    }cout << "\n";
    //}
    return 0;
}
