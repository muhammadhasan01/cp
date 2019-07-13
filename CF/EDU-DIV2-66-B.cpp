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
int l;
string s;
ll q[N];

void ovflow(){
    puts("OVERFLOW!!!");
    ex;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll MX = ((ll)1<<32)-(ll)1;
    ll x = 0, k = 1;
    ll tmp;
    deque<ll> m = {1};
    int pos = 0;

    cin >> l;
    while(l--){
        cin >> s;
        if(s[0] == 'f'){
            cin >> tmp;
            k *= tmp;
            k = min(MX+1,k);
            m.pb(k);
        }else if(s[0] == 'a'){
            if(k == MX+1)ovflow();
            if(x + k > MX)ovflow();
            x += k;
        }else if(s[0] == 'e'){
            m.pop_back();
            k = m.back();
        }
    }

    cout << x << "\n";




    return 0;
}
