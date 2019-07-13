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
map<string,string> m;
map<string,int> k;
vector<string> v = {"Reality", "Power", "Time", "Space", "Soul", "Mind"};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    m["red"] = "Reality";
    m["purple"] = "Power";
    m["blue"] = "Space";
    m["green"] = "Time";
    m["orange"] = "Soul";
    m["yellow"] = "Mind";

    cin >> n;
    forn(i,1,n){
        string x; cin >> x;
        k[m[x]]++;
    }

    cout << (6-n) << "\n";
    for(auto e:v){
        if(!k[e])cout << e << "\n";
    }





    return 0;
}
