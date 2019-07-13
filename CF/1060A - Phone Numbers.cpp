#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// Phone Numbers : https://codeforces.com/problemset/problem/1060/A


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, c = 0; cin >> N;
    string A; cin >> A;
    if(N<11){cout << "0\n";return 0;}
    for(ll i=0;i<A.size();i++){if(A[i]=='8')c++;}
    N /= 11;
    cout << min(N,c) << "\n";
    return 0;
}
