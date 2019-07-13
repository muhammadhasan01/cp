#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 100000;
ll n, k;
ll a[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(ll i=0;i<n;i++){cin >> a[i]; pq.push(a[i]);}
    ll answer = 0, temp = 0;
    while(!pq.empty()){
        if(pq.size() == 1 && pq.top() < k){cout << "-1\n"; return 0;}
        if(pq.top() >= k){break;}else{answer++;}
        temp += pq.top(); pq.pop();
        temp += 2*pq.top(); pq.pop();
        pq.push(temp); temp = 0;}
    cout << answer << "\n";
    return 0;
}
