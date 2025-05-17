#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll R, C, Q;
    cin >> R >> C >> Q;

    auto ask = [&](ll x, ll y){
        cout << "? " << x << " " << y << "\n" << flush;
        ll k; 
        cin >> k;
        return k;
    };

    // 1) get min(S)   from (1,1): k1 = min(S_A-2, S_B-2)
    ll k1 = ask(1, 1);
    // 2) get max(S)   from (R,C): k2 = min((R+C)-S_A, (R+C)-S_B)
    ll k2 = ask(R, C);
    // 3) get min(D)   from (1,C): k3 = min(D_A+(C-1), D_B+(C-1))
    ll k3 = ask(1, C);
    // 4) get max(D)   from (R,1): k4 = min((R-1)-D_A, (R-1)-D_B)
    ll k4 = ask(R, 1);

    ll Smin = k1 + 2;
    ll Smax = (R + C) - k2;
    ll Dmin = k3 - (C - 1);
    ll Dmax = (R - 1) - k4;

    // two possible matchings:
    //  A: (Smin,Dmin) & (Smax,Dmax)
    ll xA1 = (Smin + Dmin) / 2,  yA1 = (Smin - Dmin) / 2;
    ll xB1 = (Smax + Dmax) / 2,  yB1 = (Smax - Dmax) / 2;
    //  B: (Smin,Dmax) & (Smax,Dmin)
    ll xA2 = (Smin + Dmax) / 2,  yA2 = (Smin - Dmax) / 2;
    ll xB2 = (Smax + Dmin) / 2,  yB2 = (Smax - Dmin) / 2;

    if (xA1 < 1 || xA1 > R || yA1 < 1 || yA1 > C) {
        cout << "! "
             << xA2 << " " << yA2 << " "
             << xB2 << " " << yB2 << "\n"
             << flush;
        return 0;
    }

    // 5) disambiguate by querying one candidate:
    ll k5 = ask(xA1, yA1);
    if (k5 == 0) {
        // (xA1,yA1) is exactly a gold, so matching A is correct
        cout << "! " 
             << xA1 << " " << yA1 << " "
             << xB1 << " " << yB1 << "\n"
             << flush;
    } else {
        // otherwise matching B must be the real one
        cout << "! "
             << xA2 << " " << yA2 << " "
             << xB2 << " " << yB2 << "\n"
             << flush;
    }

    return 0;
}
