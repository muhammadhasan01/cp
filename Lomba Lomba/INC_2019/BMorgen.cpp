#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<LL,LL>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n,h;
    cin >> n >> h;
    pii a[n+5];
    for (LL i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    LL ans=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (LL i=1;i<=n;i++) {
        pq.push(mp(a[i].se, a[i].fi));
    }
    while (h>0 && !pq.empty()) {
        //cout << pq.top().fi << " " << pq.top().se << endl;
        ans+=pq.top().fi-pq.top().fi/2;
        h-=pq.top().se;
        pii g = make_pair(pq.top().fi/2, pq.top().se*2);
        //cout << "*" << g.fi << " " << g.se << " " << pq.size() << endl;
        pq.pop();
        if (g.fi>0) {
            pq.push(g);
        }
    }
    //cout << h << endl;
    if (h<=0) cout << ans << endl; else cout << -1 << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
