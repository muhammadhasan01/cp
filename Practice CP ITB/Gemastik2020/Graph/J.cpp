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

const int N = 2e3 + 5;
const int M = 4 * N + 5;

int n, m;
char a[N][N], b[N][N];
char c[N];
vector<int> adj[M];
int tin[M], low[M], timer = 0;
int comp[M], numComponent;
vector<int> components[M];
int compVal[M], val[M];
stack<int> st;
bool onStack[M];

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

void tarjan(int u) {
    tin[u] = low[u] = ++timer;
    st.emplace(u); onStack[u] = true;
    for (auto v : adj[u]) {
        if (tin[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] != low[u]) return;
    int w = 0; numComponent++;
    do {
        w = st.top(); st.pop();
        onStack[w] = 0;
        comp[w] = numComponent;
        components[numComponent].emplace_back(w);
    } while (w != u && !st.empty());
}

void SCC() {
    for (int i = 1; i <= 4 * n; i++) {
        if (tin[i]) continue;
        tarjan(i);
    }
}

int NOT(int x) {
    if (x & 1) return x + 1;
    return x - 1;
}

void addOR(int x, int y) {
    adj[NOT(x)].emplace_back(y);
    adj[NOT(y)].emplace_back(x);
}

void addXOR(int x, int y) {
    addOR(x, y); addOR(NOT(x), NOT(y));
}

void addXNOR(int x, int y) {
    addOR(x, NOT(y)); addOR(NOT(x), y);
}

bool isSolvable() {
    debug() << imie(range(comp + 1, comp + 1 + 4 * n));
    for (int i = 1; i <= 4 * n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
    }
    return true;
}

void assignValues() {
    memset(compVal, -1, sizeof(compVal));
    memset(val, -1, sizeof(val));
    debug() << imie(numComponent);
    for (int i = 1; i <= numComponent; i++) {
        if (compVal[i] != -1) continue;
        compVal[i] = 1;
        int u = components[i].back();
        int notComp = comp[NOT(u)];
        debug() << imie(i) imie(u) imie(notComp);
        compVal[notComp] = 0;
    }
    debug() << imie(range(compVal + 1, compVal + 1 + numComponent));
    for (int i = 1; i <= 4 * n; i++) {
        val[i] = compVal[comp[i]];
    }
    debug() << imie(range(val + 1, val + 1 + 4 * n));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x = 2 * i - 1, y = 2 * j + 2 * n - 1;
            // c[i] -> y, c[j] -> x
            if (a[i][j] == b[i][j]) {
                if (c[i] == '1' && c[j] == '1')
                    addXNOR(x, y);
                else if (c[i] == '1' && c[j] == '0')
                    addOR(NOT(y), NOT(y));
                else if (c[i] == '0' && c[j] == '1')
                    addOR(NOT(x), NOT(x));
            } else {
                if (c[i] == '1' && c[j] == '1')
                    addXOR(x, y);
                else if (c[i] == '1' && c[j] == '0')
                    addOR(y, y);
                else if (c[i] == '0' && c[j] == '1')
                    addOR(x, x);
                else
                    dismiss();
            }
        }
    }
    SCC();
    if (!isSolvable()) dismiss();
    assignValues();
    int ans = 0;
    vector<int> R, C;
    for (int r = 1; r <= 2 * n; r += 2) {
        if (val[r] == 1) {
            ++ans;
            R.emplace_back(r / 2);
        }
    }
    for (int c = 2 * n + 1; c <= 4 * n; c += 2) {
        if (val[c] == 1) {
            ++ans;
            C.emplace_back(c / 2 - n);
        }
    }
    cout << ans << '\n';
    for (int row : R) cout << "row " << row << '\n';
    for (int col : C) cout << "col " << col << '\n';

    return 0;
}