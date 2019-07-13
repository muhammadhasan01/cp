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

const int N = 3e5+5;
int n;
int one, two;

vector<int> prime;
bitset<N> vis;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    forn(i,1,n){
        int x; cin >> x;
        if(x == 1)one++;
        else two++;
    }

    vector<int> ans;
    if(two > 0){
        two--;
        ans.pb(2);
    }else if(one > 0){
        one--;
        ans.pb(1);
    }

    if(one > 0){
        one--;
        ans.pb(1);
    }else if(two > 0){
        two--;
        ans.pb(2);
    }

    //cerr << one << " " << two << "\n";
    //cout << len(ans) << "\n";

    while(two > 0){
        two--;
        ans.pb(2);
    }

    while(one > 0){
        one--;
        ans.pb(1);
    }

    for(auto e:ans)cout << e << " ";



    return 0;
}
