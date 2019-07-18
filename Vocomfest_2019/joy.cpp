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

string s;

int f[6];

int c(char x){
    if(x == 'a')return 1;
    if(x == 'i')return 2;
    if(x == 'u')return 3;
    if(x == 'e')return 4;
    if(x == 'o')return 5;
    else return 0;
}

int l = 0, r = 0;
ll ans = 0;

bool check(){
    if(f[1] > 0 && f[2] > 0 && f[3] > 0 && f[4] > 0 && f[5] > 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int lens = len(s);
    while(l < lens && r < lens){
        f[c(s[r])]++;
        //cerr << l << " and " << r << "\n";
        while(check() && l <= r){
            ans += lens - r;
            //cerr << "(" << l << "," << r << ") => " << lens-r << "\n";
            f[c(s[l])]--;
            l++;
        }
        r++;
    }

    cout << ans << '\n';

    return 0;
}
