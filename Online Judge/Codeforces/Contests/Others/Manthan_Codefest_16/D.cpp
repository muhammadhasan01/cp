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

const int N = 1e3 + 5;

int n;
int restore[N];
unordered_map<int, int> mp;

int get(int x, int y) {
    int z = x + y;
    restore[1] = x, restore[2] = y;
    mp[x]--, mp[y]--;
    for (int i = 3; i <= n; i++) {
        if (mp[z] == 0) {
            for (int j = i - 1; j >= 1; j--) mp[restore[j]]++;
            return i - 1;
        }
        mp[z]--;
        restore[i] = z;
        x = y, y = z;
        z = x + y;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        nums.emplace_back(x);
        mp[x]++;
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int ans = 2;
    for (int x : nums) {
        for (int y : nums) {
            if (x == y && mp[x] < 2) continue;
            ans = max(ans, get(x, y));
            if (ans == n) {
                cout << ans << '\n';
                return 0;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}