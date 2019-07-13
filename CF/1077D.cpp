#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef pair<long double, long double> pld;

int k,n;
ll t;
unordered_map<ll,int> m;
priority_queue<pair<ld,pld> > pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;
    for(int i=1;i<=k;i++){cin >> t; m[t]++;}

    for(auto it = m.begin(); it != m.end(); it++){
        pq.push(mp(it->ss, mp(1, it->ff)));
        //cout << it->ff << " = " << it->ss << "\n";
    }

    int p = 0;
    while(p != n){
        ld x = pq.top().ff, y = pq.top().ss.ff , z = pq.top().ss.ss;
        //cout << x << " => " << y << "," << z << "\n";
        cout << z;
        pq.pop();
        if(m[z]/(y+1) >= 1){
            pq.push(mp(m[z]/(y+1),mp(y+1, z)));
        }
        p++;
        if(p!=n)cout << " ";
    }cout << "\n";
    return 0;
}
