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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    vector<long long> nums;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        nums.emplace_back(v[i].first - 1);
        nums.emplace_back(v[i].first);
        nums.emplace_back(v[i].first + 1);
        nums.emplace_back(v[i].second - 1);
        nums.emplace_back(v[i].second);
        nums.emplace_back(v[i].second + 1);
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int len = nums.size();
    for (int i = 0; i < n; i++) {
        v[i].first = lower_bound(nums.begin(), nums.end(), v[i].first) - nums.begin() + 1;
        v[i].second = lower_bound(nums.begin(), nums.end(), v[i].second) - nums.begin() + 1;
    }
    vector<int> cnt(len + 5);
    for (int i = 0; i < n; i++) {
        cnt[v[i].first]++;
        cnt[v[i].second + 1]--;
    }
    for (int i = 1; i <= len + 1; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<long long> ans(n + 5);
    int last = 0;
    for (int i = 1; i <= len; i++) {
        if (cnt[i] != cnt[i - 1]) {
            last = i;
        }
        if (cnt[i] != cnt[i + 1] && cnt[i] > 0) {
            ans[cnt[i]] += nums[i - 1] - nums[last - 1] + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}