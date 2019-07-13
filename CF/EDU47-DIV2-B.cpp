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

    cin >> s;
    n = len(s);
    string ans = "", temp = "";
    forn(i,0,n-1){
        if(s[i] != '1')ans += s[i];
        else temp += s[i];
    }

    string res = "";
    n = len(ans);
    int pos = -1;
    forn(i,0,n-1){
        if(pos == -1 && ans[i] == '2'){
            pos = i;
            res += temp;
        }
        res += ans[i];
    }
    if(pos == -1)res += temp;
    cout << res << "\n";





    return 0;
}
