#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    vector<int> lens(K);
    for (int i = 0; i < K; i++) {
        cin >> lens[i];
    }
    int q;
    cin >> q;
    vector<int> par(lens[0] + lens[1] + 5);
    auto get_id = [&](string& s) -> int {
        char cc = s[0];
        s.erase(s.begin());
        int num = stoi(s);
        if (cc == 'B') {
            num += lens[0];
        }
        return num;
    };
    int R1 = 1;
    int B1 = lens[0] + 1;
    for (int it = 0; it < K; it++) {
        for (int i = 2; i <= lens[it]; i++) {
            string s;
            cin >> s;
            int pos = i + (it == 1 ? lens[0] : 0);
            par[pos] = get_id(s);
        }
    }
    auto crossover = [&](string& u, string& v) -> void {
        int nu = get_id(u);
        int nv = get_id(v);
        par[nu] = nv;
    };
    vector<bool> vis(lens[0] + lens[1] + 5);
    auto battle = [&](string& u, string& v) -> void {
        int nu = get_id(u);
        int nv = get_id(v);
        auto ups = [&](int u) -> pair<int, int> {
            int dist = 0;
            vector<int> pot = {R1, B1};
            vis[R1] = vis[B1] = true;
            while (true) {
                if (vis[u]) {
                    break;
                }
                vis[u] = true;
                pot.emplace_back(u);
                u = par[u];
                dist++;
            }
            for (int x : pot) {
                vis[x] = false;
            }
            return make_pair(u, dist);
        };
        auto [xu, du] = ups(nu);
        auto [xv, dv] = ups(nv);
        bool nru = (xu != R1 && xu != B1);
        bool nrv = (xv != R1 && xv != B1);
        auto output = [&](int x, int d) {
            cout << (x == R1 ? "RED" : "BLUE") << ' ' << d << '\n';
        };
        if (nru && nrv) {
            cout << "NONE" << '\n';
        } else if (nru) {
            output(xv, dv);
        } else if (nrv) {
            output(xu, du);
        } else {
            if (du == dv) {
                if (xu == xv) {
                    output(xu, du);
                } else {
                    cout << "TIE" << ' ' << du << '\n';
                }
            } else if (du < dv) {
                output(xu, du);
            } else if (dv < du) {
                output(xv, dv);
            }
        }
    };
    while (q--) {
        char tp;
        cin >> tp;
        string u, v;
        cin >> u >> v;
        if (tp == 'c') {
            crossover(u, v);
        } else if (tp == 'w') {
            battle(u, v);
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}