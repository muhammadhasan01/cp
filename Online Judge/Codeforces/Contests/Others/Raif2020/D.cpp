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

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> ans;
    stack<pair<int, int>> dq, two, three;
    int row = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            ans.emplace_back(row, i);
            dq.emplace(row, i);
            --row;
        } else if (a[i] == 2) {
            if (dq.empty()) dismiss();
            auto cur = dq.top(); dq.pop();
            ans.emplace_back(cur.first, i);
            two.emplace(cur.first, i);
        } else if (a[i] == 3) {
            bool ok = false;
            if (!two.empty()) {
                ok = true;
                auto cur = two.top(); two.pop();
                ans.emplace_back(row, i); ans.emplace_back(row, cur.second);
            } else if (!three.empty()) {
                ok = true;
                auto cur = three.top(); three.pop();
                ans.emplace_back(row, i); ans.emplace_back(row, cur.second);
            } else if (!dq.empty()) {
                ok = true;
                auto cur = dq.top(); dq.pop();
                ans.emplace_back(row, i); ans.emplace_back(row, cur.second);
            }
            if (!ok) dismiss();
            three.emplace(row, i);
            row--;
        }
    }
    cout << ans.size() << '\n';
    for (auto& e : ans) {
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }

    return 0;
}