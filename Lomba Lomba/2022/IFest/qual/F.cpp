#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 51;

void invalid() {
    cout << "Invalid Input\n";
    exit(0);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // string iline;
    // getline(cin, iline);
    // stringstream ss(iline);
    vector<ll> vec;
    {
        ll inp;
        while (cin >> inp) {
            vec.push_back(inp);
        }    
    }
    if (vec.size() <= 7 || 50 < vec.size()) {
        invalid();
    }
    auto get_std = [&](int l, int r) -> ll {
        ll avg = 0;
        for (int i = l; i <= r; i++) {
            avg += vec[i];
        }
        ll n = r - l + 1;
        avg /= n - 1;
        ll ret = 0;
        for (int i = l; i <= r; i++) {
            ll cur = vec[i] - avg;
            ret += cur * cur;
        }
        ret /= n - 1;
        return sqrt(ret);
    };
    int len = vec.size();
    for (int i = 7; i < len; i++) {
        int l = i - 7, r = l + 6;
        ll std = get_std(l, r);
        
        ll diff = vec[i] - vec[i - 1];
        if (diff > std) {
            cout << "up";
        } else if (diff < -std) {
            cout << "down";
        } else {
            cout << "flat";
        }
        if (i < len - 1) cout << ' ';
        else cout << '\n';
    }

    return 0;
}