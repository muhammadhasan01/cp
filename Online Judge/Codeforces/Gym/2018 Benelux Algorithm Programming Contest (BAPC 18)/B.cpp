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

const int INF = 2e9;
const int day_date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int pre[12];

int dist(pair<int, int> x, pair<int, int> y) {
    if (x == y) return 0;
    x.first--, y.first--;
    int d_1 = (x.first > 0 ? pre[x.first - 1] : 0) + x.second;
    int d_2 = (y.first > 0 ? pre[y.first - 1] : 0) + y.second;
    if (d_1 > d_2)
        return 365 - (d_1 - d_2);
    // debug() << imie(x) imie(y) imie(d_1) imie(d_2);
    return d_2 - d_1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 12; i++) {
        if (i > 0) pre[i] = pre[i - 1];
        pre[i] += day_date[i];
    }
    debug() << range(pre, pre + 12);
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        string name; cin >> name;
        string res; cin >> res;
        v[i].first = stoi(res.substr(0, 2));
        v[i].second = stoi(res.substr(3, 2));
    }
    sort(v.begin(), v.end());
    debug() << imie(v);
    int month = -1, day = -1;
    int res = 0;
    for (int m = 10; m <= 12; m++) {
        for (int d = (m == 10 ? 28 : 1); d <= day_date[m - 1]; d++) {
            pair<int, int> cur_pair = make_pair(m, d);
            int cur = INF;
            for (const auto& e : v) {
                int temp = dist(e, cur_pair);
                if (temp < 0) continue;
                cur = min(cur, temp);
            }
            if (cur > res) {
                debug() << imie(cur) imie(res) imie(m) imie(d);
                res = cur;
                month = m, day = d;
            }
        }
    }
    for (int m = 1; m <= 10; m++) {
        for (int d = 1; d <= (m == 10 ? 27 : day_date[m - 1]); d++) {
            pair<int, int> cur_pair = make_pair(m, d);
            int cur = INF;
            for (const auto& e : v) {
                int temp = dist(e, cur_pair);
                if (temp < 0) continue;
                cur = min(cur, temp);
            }
            if (cur > res) {
                debug() << imie(cur) imie(res) imie(m) imie(d);
                res = cur;
                month = m, day = d;
            }
        }
    }
    if (month < 10) cout << 0;
    cout << month << '-';
    if (day < 10) cout << 0;
    cout << day << '\n';

    return 0;
}