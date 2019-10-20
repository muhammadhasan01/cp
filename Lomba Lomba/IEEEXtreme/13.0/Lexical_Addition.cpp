#include <bits/stdc++.h>

// author : mastre

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

ll n,a,b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;

    ll del=b-a+1;
    ll sisa=n%a;
    ll cnt=n/a;

    if (sisa>cnt*del){
        cout << "NO" << el;
        return 0;
    }

    ll tot=0;
    cout << "YES" << el;
    for (;tot<n;tot+=a){
        cout << a << " ";
    }
    cout << el;

    return 0;
}
