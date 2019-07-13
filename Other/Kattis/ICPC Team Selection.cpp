#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://open.kattis.com/problems/icpcteamselection

int t,n,x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        deque<int> dq;
        for(int i=1;i<=3*n;i++){
            cin >> x;
            dq.push_back(x);
        }
        sort(dq.begin(),dq.end());
        int ans = 0;
        while(!dq.empty()){
            dq.pop_back();
            ans += dq.back();
            dq.pop_back();
            dq.pop_front();
        }
        cout << ans << "\n";
    }

    return 0;
}
