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

int q;
ll b, x;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    while (q--){
        cin >> b >> x;

        ll len=1;
        ll kurang=b;

        if (b==1){
            cout << "a" << el;
            continue;
        }

        while (x>=kurang*len){
            x-=kurang*len;
            len++;
            kurang*=b;
        }

        ll pos=(x)/len;
        ll id=(x)%len;
        ll vlen=0;
        vector <ll> v;
        while (pos){
            v.pb(pos%b);
            pos/=b;
            vlen++;
        }

        while (vlen<len){
            vlen++;
            v.pb(0);
        }
        reverse(v.begin(),v.end());
        cout << char((int)v[id] + (int)'a') << el;

    }

    return 0;
}
