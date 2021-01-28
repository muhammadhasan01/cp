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

const int N = 2e4 + 10;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S, T;
    cin >> S >> T;

    map<pair<int, int>, int> mp;
    vector<pair<int, int>> memo(N);
    int id = 0;
    
    auto getId = [&](pair<int, int> p) -> int {
        if (mp.count(p) == 0) {
            memo[id] = p;
            mp[p] = id++;
        }
        return mp[p];
    };
    
    auto solve = [&](string& X) -> deque<int> {
        deque<int> dq;
        for (int i = 2; i < N; i++) {
            dq.emplace_back(-i);
        }
        for (char cc : X) {
            if (cc == 'C') {
                dq.emplace_front(dq.front());
            } else if (cc == 'D') {
                dq.pop_front();
            } else if (cc == 'L') {
                if (dq.front() < 0) return {-1};
                dq.front() = memo[dq.front()].first;
            } else if (cc == 'P') {
                int a = dq.front(); dq.pop_front();
                int b = dq.front(); dq.pop_front();
                dq.emplace_front(getId(make_pair(a, b)));
            } else if (cc == 'R') {
                if (dq.front() < 0) return {-1};
                dq.front() = memo[dq.front()].second;
            } else if (cc == 'S') {
                int a = dq.front(); dq.pop_front();
                int b = dq.front(); dq.pop_front();
                dq.emplace_front(a); dq.emplace_front(b);
            } else if (cc == 'U') {
                if (dq.front() < 0) return {-1};
                int a = dq.front();
                dq.pop_front();
                dq.emplace_front(memo[a].second);
                dq.emplace_front(memo[a].first);
            }
        }
        return dq;
    };

    cout << (solve(S) == solve(T) ? "True" : "False") << '\n';

    return 0;
}