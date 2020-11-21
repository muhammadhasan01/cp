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

const int N = (1 << 16) + 10;

int ans[N];
int ask_xor[N];

int ask(string s, int i, int j) {
    cout << s << ' ' << i << ' ' << j << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        ask_xor[i] = ask("XOR", i, i + 1);
    }

    int a = ask("AND", 1, 2);
    // int b = ask("OR", 2, 3);
    int c = ask("OR", 1, 2);
    int d = ask("AND", 1, 3);
    int e = (ask_xor[1] ^ ask_xor[2]);
    for (int i = 20; i >= 0; i--) {
        int bit_a = (a & (1 << i));
        // int bit_b = (b & (1 << i));
        int bit_c = (c & (1 << i));
        int bit_d = (d & (1 << i));
        int bit_e = (e & (1 << i));
        if (bit_c == 0) {
            // 0 0 ?
            continue;
        }
        if (bit_a == 1) {
            // 1 1 ?
            ans[1] |= (1 << i);
            continue;
        }
        // 1 0 ?, 0 1 ?
        if (bit_d == 1) {
            // 1 0 1
            ans[1] |= (1 << i);
            continue;
        }
        // 1 0 0, 0 1 1
        if (bit_e == 0) {
            // 1 0 1
            ans[1] |= (1 << i);
            continue;
        }
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
        res = (res ^ ask_xor[i]);
        ans[i + 1] = (res ^ ans[1]);
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
        if (i == n)
            cout << endl;
        else
            cout << ' ';
    }

    return 0;
}