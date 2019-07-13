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

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    deque<char> ans;
    int cnt = 1;
    for(auto e:s){
        if(cnt){
            ans.pb(e);
            cnt = 1-cnt;
        }else{
            if(ans.back() == e)continue;
            ans.pb(e);
            cnt = 1-cnt;
        }
    }

    if(len(ans)&1)ans.pop_back();
    cout << len(s) - len(ans) << "\n";
    for(auto e:ans)cout << e;
    cout << "\n";

    return 0;
}
