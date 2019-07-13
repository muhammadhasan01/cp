#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 30;
int n,k,c = 1;
map<string,int> m;
float x;
string t1,t2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> n;
        if(n==0)break;
        for(int i=1;i<=n;i++){
            cin >> t1;
            m[t1] = i;
        }
        cin >> k;
        float v[N+2][N+2];
        MEM(v,0);
        for(int i=1;i<=k;i++){
            cin >> t1 >> x >> t2;
            v[m[t1]][m[t2]] = x;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(v[i][j] < v[i][k]*v[k][j]){
                        v[i][j] = v[i][k]*v[k][j];
                    }
                }
            }
        }
        bool y = false;
        for(int i=1;i<=n;i++){
            if(v[i][i] > 1){
                y = true; break;
            }
        }
        cout << "Case " << c << ": ";
        if(y){
            cout << "Yes\n";
        }else{ cout << "No\n";}
        c++;
    }

    return 0;
}
