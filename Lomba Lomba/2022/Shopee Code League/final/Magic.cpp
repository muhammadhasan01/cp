#include <bits/stdc++.h>

using namespace std;

#define int long long
#define forn(i,n) for(int i = 0; i <(int)n; ++i)
#define vi vector<int>

const int MOD = 1000000007;
//const int MOD = 998244353;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n; cin >> n;
    if(!(n & (n+1))){
        cout << "1\n";
    }
    else cout << "0\n";
    return 0;
}
