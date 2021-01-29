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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int S, L, N;
    cin >> S >> L >> N;
    vector<string> names(S);
    for (int i = 0; i < S; i++) {
        cin >> names[i];
    }
    sort(names.begin(), names.end());
    map<string, int> mp;
    vector<string> animals(S);
    {
        int id = 0;
        for (string& str : names) {
            animals[id] = str;
            mp[str] = id++;
        }
    }
    vector<vector<bool>> swappable(S, vector<bool>(S));
    for (int i = 0; i < L; i++) {
        string A, B;
        cin >> A >> B;
        int u = mp[A], v = mp[B];
        swappable[u][v] = swappable[v][u] = true;
    }
    vector<int> q(N);
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        q[i] = mp[str];
    }
    vector<int> ans(N);
    vector<int> cur_block(S);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S; j++) {
            while (cur_block[j] < N && (q[cur_block[j]] == -1 || swappable[j][q[cur_block[j]]]))
                cur_block[j]++;
            if (cur_block[j] < N && q[cur_block[j]] == j) {
                q[cur_block[j]] = -1;
                ans[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << animals[ans[i]] << " \n"[i == N - 1];
    }

    return 0;
}