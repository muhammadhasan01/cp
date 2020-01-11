#include <bits/stdc++.h>


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

ll n;
long double res = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (ll i=2;i<=n;i++){
        long double mx = n;
        ll temp = (i * (i-(ll)1));
        long double now = temp;
        res += now / mx;
    }
    cout << fixed << setprecision(11) << res << el;

    return 0;
}
