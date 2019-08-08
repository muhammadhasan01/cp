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

// Vasya and chocolate

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    ll s,a,b,c,k,free;
    while(T--){
        cin >> s >> a >> b >> c;
        k = s/c;
        free = (k/a)*b;
        cout << k+free << "\n";
    return 0;}
}
