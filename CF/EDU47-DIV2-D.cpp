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

const int N = 1e5+5;
int n,m;
vector<pii> ans;
vector<int> pre[N];

void answer(){
    cout << "Possible" << "\n";
    for(auto e:ans)cout << e.ff << " " << e.ss << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    if(m < n-1){
        puts("Impossible");
    }else{
        int cnt = 0;
        forn(i,1,n){
            if(i == 1){
                for(int j=i+1;j<=n;j+=i){
                    ans.pb({i,j});
                    pre[j].pb(i);
                    cnt++;
                    if(cnt == m){
                        answer(); ex;
                    }
                }
            }else if(i == 2){
                for(int j=i+1;j<=n;j+=i){
                    ans.pb({i,j});
                    pre[j].pb(i);
                    cnt++;
                    if(cnt == m){
                        answer(); ex;
                    }
                }
            }else{
                for(auto e:pre[i]){
                    for(int j=e+i;j<=n;j+=i){
                        ans.pb({i,j});
                        pre[j].pb(i);
                        cnt++;
                        if(cnt == m){
                            answer(); ex;
                        }
                    }
                }
            }
        }
        puts("Impossible");
    }






    return 0;
}
