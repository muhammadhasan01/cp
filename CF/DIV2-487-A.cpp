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
string m = "ABC";

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    vector<string> v;
    do{
        v.pb(m);
        //cerr << m << " ";
    }while(next_permutation(all(m)));

    int k = len(s);
    for(auto e:v){
        forn(i,0,k-3){
            if(s[i] == e[0] && s[i+1] == e[1] && s[i+2] == e[2]){
                puts("Yes"); ex;
            }
        }
    }

    puts("No");



    return 0;
}
