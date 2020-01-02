// author : moondemon68
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--) {
        int n,m;
        cin >> n >> m;
        string s,t,d;
        cin >> s >> d >> t;
        vector<priority_queue<int,vector<int>,greater<int>>> q(30);
        for (int i=0;i<s.size();i++) {
            q[s[i]-'a'].push(d[i]-'0');
        }
        int ans=0;
        for (int i=0;i<t.size();i++) {
            if (!q[t[i]-'a'].empty()) {
                //cout << q[t[i]-'a'].top() << endl;
                ans += q[t[i]-'a'].top();
                q[t[i]-'a'].pop();
            } else {
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
