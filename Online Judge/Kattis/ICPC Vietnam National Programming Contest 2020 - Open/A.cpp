#include <bits/stdc++.h>

using namespace std;

/** START OF TEMPLATE DEBUGGER **/
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/** END OF TEMPLATE DEBUGGER **/

const vector<string> month = {"Jan", "Feb", "Mar", "Apr",
    "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

map<string, pair<int, int>> mp;

int F(string euy, int x) {
    int res = x;
    for (int i = 0; i < 12; i++) {
        if (month[i] == euy) {
            return res;
        }
        res += 31;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    mp["Aries"] = make_pair(F("Mar", 21), F("Apr", 20));
    mp["Taurus"] = make_pair(F("Apr", 21), F("May", 20));
    mp["Gemini"] = make_pair(F("May", 21), F("Jun", 21));
    mp["Cancer"] = make_pair(F("Jun", 22), F("Jul", 22));
    mp["Leo"] = make_pair(F("Jul", 23), F("Aug", 22));
    mp["Virgo"] = make_pair(F("Aug", 23), F("Sep", 21));
    mp["Libra"] = make_pair(F("Sep", 22), F("Oct", 22));
    mp["Scorpio"] = make_pair(F("Oct", 23), F("Nov", 22));
    mp["Sagittarius"] = make_pair(F("Nov", 23), F("Dec", 21));
    mp["Capricorn"] = make_pair(F("Dec", 22), F("Jan", 20));
    mp["Aquarius"] = make_pair(F("Jan", 21), F("Feb", 19));
    mp["Pisces"] = make_pair(F("Feb", 20), F("Mar", 20));

    int tc;
    cin >> tc;
    while (tc--) {
        int d; string m;
        cin >> d >> m;
        int x = F(m, d);
        bool ok = false;
        for (auto& e : mp) {
            if (e.second.first <= x && x <= e.second.second) {
                cout << e.first << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << "Capricorn" << '\n';
        }
    }

    return 0;
}