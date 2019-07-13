#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define first fs
#define second sc
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// Jumping Jack
// Find the least t_n where t_n = 1+2+...+n so that t_n >= x and t_n has the same parity with x

ll answer(ll x){
    x = abs(x);
    ll a = (-1+sqrt(1+8*x))/2; ll k = a*(a+1)/2;
    while((x+k)%2!=0 || x > k){k+=a+1;a++;}
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N; cin >> N; cout << answer(N) << "\n";
    return 0;
}

// detailed solution : https://stackoverflow.com/questions/15406950/deciding-on-an-algorithm-for-jumping-jack
