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

map<char,int> m;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    m['a'] = 1, m['i'] = 1, m['u'] = 1, m['e'] = 1, m['o'] = 1;
    m['n'] = 2;
    cin >> s;
    int n = len(s);
    forn(i,0,n-1){
        if(m[s[i]] == 0){
            if(i == n-1){
                puts("NO"); ex;
            }else if(m[s[i+1]] == 0 || m[s[i+1]] == 2){
                puts("NO"); ex;
            }
        }
    }

    puts("YES");





    return 0;
}
