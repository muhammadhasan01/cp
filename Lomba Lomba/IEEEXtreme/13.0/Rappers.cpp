#include <bits/stdc++.h>

// author : mastre, mhasan01

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

ll a,b;

// find n and n
ll f(ll n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 3 == 1) {
        return (n / 3) * 2 + f(1);
    } else if (n % 3 == 2) {
        return (n / 3) * 2 + f(2);
    } else {
        return (n / 3) * 2;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    ll ans=0;
    if (a>b) swap(a,b);

    ll del=b-a;

    if (del<=a){
        ans+=del;
        b-=del+del;
        a-=del;

        ans += f(a);
    } else{
        ans+=a;
    }

    cout << ans << el;

    return 0;
}
