// author: Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e3 + 10;

int q, n;
int ar[N][N];
set <int> ntaken;
set <pii> setdah[N]; // urutan, node
vector <pii> edge;
int mat[N][N];
bool taken[N];

void init(){
    ntaken.clear();
    fill(taken, taken + n + 2, 0);
    for (int i=1;i<=n;i++){
        setdah[i].clear();
    }
    edge.clear();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        init();
        for (int i=1;i<=n;i++){
            ntaken.insert(i);
            for (int j=1;j<=n;j++){
                cin >> ar[i][j];
                mat[i][ar[i][j]] = j;
                if(j != 1) setdah[i].insert(mp(j, ar[i][j]));
            }
        }
        int ambil = n;
        while ((int)ntaken.size() > 1){
            int node = *ntaken.begin();
            auto fur1 = *setdah[node].rbegin();
            while (taken[fur1.se]){
                setdah[node].erase(fur1);
                fur1 = *setdah[node].rbegin();
            }
            auto cari = *setdah[fur1.se].begin();
            while (taken[cari.se]){
                setdah[fur1.se].erase(cari);
                cari = *setdah[fur1.se].begin();
            }
            edge.pb(mp(fur1.se, cari.se));
            ntaken.erase(fur1.se);
            taken[fur1.se] = 1;
            // for (auto x : ntaken){
            //     setdah[x].erase(mp(mat[x][fur1.se], fur1.se));
            // }
        }
        for (auto x : edge){
            cout << x.fi << " " << x.se << el;
        }
        cout << el;
    }

    return 0;
}