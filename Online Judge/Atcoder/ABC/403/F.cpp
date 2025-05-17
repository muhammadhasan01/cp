#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct State {
    int len;
    string repr;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<State> E(N + 1, {INF, ""});
    vector<State> T(N + 1, {INF, ""});
    vector<State> F(N + 1, {INF, ""});
    {
        long long v = 0;
        string s;
        while (true) {
            v = v * 10 + 1;
            if (v > N) break;
            s.push_back('1');
            int L = (int)s.size();
            E[v] = T[v] = F[v] = {L, s};
        }
    }
    bool changed = true;
    for (int pass = 0; changed && pass < 10; pass++) {
        changed = false;
        for (int x = 1; x <= N; ++x) {
            if (F[x].len < T[x].len) {
                T[x] = F[x];
                changed = true;
            }
            if (T[x].len < E[x].len) {
                E[x] = T[x];
                changed = true;
            }
            for (int d = 2, sq = (int)sqrt(x); d <= sq; d++) if (x % d == 0) {
                int a = d, b = x / d;
                auto relax_mult = [&](int l, int r) {
                    if (T[l].len == INF || F[r].len == INF) return;
                    int candLen = T[l].len + 1 + F[r].len;
                    if (candLen < T[x].len) {
                        T[x] = {candLen, T[l].repr + '*' + F[r].repr};
                        changed = true;
                    }
                };
                relax_mult(a, b);
                if (a != b) relax_mult(b, a);
            }
            if (T[x].len < E[x].len) {
                E[x] = T[x];
                changed = true;
            }
            for (int a = 1; a < x; a++) {
                int b = x - a;
                if (E[a].len == INF || T[b].len == INF) continue;
                int candLen = E[a].len + 1 + T[b].len;
                if (candLen < E[x].len) {
                    E[x] = {candLen, E[a].repr + '+' + T[b].repr};
                    changed = true;
                }
            }
            if (E[x].len < INF) {
                bool needPar = E[x].repr.find('+') != string::npos || E[x].repr.find('*') != string::npos;
                int candLen = E[x].len + (needPar ? 2 : 0);
                string cand = needPar ? '(' + E[x].repr + ')' : E[x].repr;
                if (candLen < F[x].len) {
                    F[x] = {candLen, cand};
                    changed = true;
                }
            }
        }
    }
    cout << E[N].repr << '\n';
    
    return 0;
}
