#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e3 + 10;
const int R = 60;
const int T = 20;

int q;
int r, c, n;
bool ada[T];
bool wall[R][R];
int bom[R][R];

pii start[2];

set<pii> dp[T][R][R];

int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};

void init(){
    fill(ada, ada + T, 0);
    for (int i=0;i<=r + 2;i++){
        for (int j=0;j<=c + 2;j++){
            wall[i][j] = 1;
            bom[i][j] = 0;
            for (int k=0;k<T;k++){
                dp[k][i][j].clear();
            }
        }
    }
}
bool bisa(int mx){
    dp[1][start[0].fi][start[0].se].insert(start[1]);
    if (mx == 0) return 1;

    for (int t=2;t<T;t++){
        bool masih = 0;
        for (int i=1;i<=r;i++){
            for (int j=1;j<=c;j++){
                if (wall[i][j]) continue;

                for (int si=0;si<4;si++){
                    int bi = i + di[si];
                    int bj = j + dj[si];

                    if (ada[t]){
                        if (bom[i][j] == t){
                            if (!dp[t - 1][bi][bj].empty() && (dp[t - 1][bi][bj].size() > 1 || dp[t - 1][bi][bj].find(mp(i, j)) == dp[t - 1][bi][bj].end())){
                                dp[t][i][j].insert(mp(bi, bj));
                                masih = 1;
                            }
                        }
                    } else if (bom[i][j] != t - 1){
                        if (!dp[t - 1][bi][bj].empty() && (dp[t - 1][bi][bj].size() > 1 || dp[t - 1][bi][bj].find(mp(i, j)) == dp[t - 1][bi][bj].end())){
                            dp[t][i][j].insert(mp(bi, bj));
                            masih = 1;
                        }
                    }
                }
            }
        }
        if (masih && t > mx) return 1;
        else if (!masih) break;
    }
    return 0;
}

void solve(){
    cin >> r >> c >> n;
    init();
    for (int i=1;i<=r;i++){
        string s;
        cin >> s;
        for (int j=1;j<=c;j++){
            wall[i][j] = s[j - 1] == '#';
        }
    }
    for (int i=0;i<2;i++){
        cin >> start[i].fi >> start[i].se;
        start[i].fi++;
        start[i].se++;
    }
    bool ok = 1;

    int mx = -1;
    for (int i=1;i<=n;i++){
        int a, b, t;
        cin >> a >> b >> t;

        a++;
        b++;
        if (ada[t]){
            ok = 0;
        }
        mx = max(mx, t);
        ada[t] = 1;
        bom[a][b] = t;
        if (t == 0){
            if (start[1] != mp(a, b)) ok = 0;
        } else if (t == 1){
            if (start[0] != mp(a, b)) ok = 0;
        }
    }
    if (!ok){
        cout << "GAME OVER" << el;
        return;
    }
    if (bisa(mx)){
        cout << "VICTORY" << el;
    } else{
        cout << "GAME OVER" << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}