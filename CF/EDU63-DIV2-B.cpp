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
int n;
string s;

int par[N];

int find(int k){
    if(par[k] == k)return k;
    return par[k] = find(par[k]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    deque<pair<char,int> > v1,v2;
    forn(i,0,n-1){
        par[i] = i;
        if(s[i] == '8'){
            v1.pb({s[i], i});
        }else{
            v2.pb({s[i], i});
        }
    }

    int turn = 1;
    while(n > 11){
        if(turn){
            if(v2.empty()){
                int k = v1.front().ss;
                par[k] = find(k+1);
                v1.pop_front();
            }else{
                int k = v2.front().ss;
                par[k] = find(k+1);
                v2.pop_front();
            }
        }else{
            if(v1.empty()){
                int k = v2.front().ss;
                par[k] = find(k+1);
                v2.pop_front();
            }else{
                int k = v1.front().ss;
                par[k] = find(k+1);
                v1.pop_front();
            }
        }

        n--;
        turn = 1 - turn;
    }

    int k = find(0);
    if(s[k] == '8'){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

    return 0;
}
