#include <bits/stdc++.h>
using namespace std;
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

const int INF = 2e9;

vector<int> divisor(int x) {
	vector<int> ret;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			ret.emplace_back(i);
			if (i * i != x) ret.emplace_back(x / i);
		}
	}
	return ret;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
	int n;
	cin >> n;
	int mini = INF;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int d : divisor(x)) {
			mp[d] = __gcd(mp[d], x);
		}
		mini = min(mini, x);
	}
	int ans = 0;
	for (auto& e : mp) {
		if (e.first > mini) continue;
		ans += (e.first == e.second);
	}
	cout << ans << '\n';
 
    return 0;
}