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
const int T = 26;
string t = "abcdefghijklmnopqrstuvwxyz";
vector<char> c[T+2];
string a[N+2];
stack<char> s;
int vis[T+2],n;
bool check = false;

void toposort(int x){
    for(int j=0; j<c[x].size();j++){
        int temp = c[x][j]-int('a')+1;
        if(vis[temp]==0){
            vis[temp] = 1;
            toposort(temp);
        }else if(vis[temp]==1){
            check = true;
        }
    }
    vis[x] = 2;
    s.push(char(int('a')+x-1));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int y, z = 0;
    if(n==1){cout << t << "\n";}else{
        MEM(vis,0);
        for(int i=1;i<n;i++){
            if(a[i][0]!=a[i+1][0]){
                int x = int(a[i][0])-int('a')+1;
                if(z==0){y=x;z++;}
                c[x].pb(a[i+1][0]);
            }else{
                if(a[i]==a[i+1]){continue;}else{
                    bool ter = true;
                    for(int j=0;j<min(a[i].size(),a[i+1].size());j++){
                        if(a[i][j]!=a[i+1][j]){
                            int x = int(a[i][j])-int('a')+1; if(z==0){y=x;z++;}
                            c[x].pb(a[i+1][j]);
                            ter = false;
                            break;
                        }
                    }
                    if(ter && a[i].size()>a[i+1].size()){cout << "Impossible\n"; return 0;}
                }
            }
        }
    }
    if(z==0){cout << t << "\n"; return 0;}
    for(int i=1;i<=26;i++){
        if(vis[i]==0){
            vis[i] = true;
            toposort(i);
            if(check){cout << "Impossible\n"; return 0;}
        }
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }cout << "\n";
    return 0;
}
