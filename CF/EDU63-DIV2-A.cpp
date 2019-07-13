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

#define pci pair<char,int>

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    //priority_queue<pii, vector<pii>, greater<pii> > pq1;
    priority_queue<pci> pq;
    forn(i,0,n-1){
        if(pq.empty()){
            pq.push({s[i],i+1});
        }else{
            if(s[i] < pq.top().ff){
                cout << "YES\n";
                cout << pq.top().ss << " " << i+1 << "\n";
                return 0;
            }else{
                pq.push({s[i],i+1});
            }
        }
        //cerr << pq.top().ff << "\n";
    }

    cout << "NO\n";

    return 0;
}
