// author : Mastre
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

const int N = 710;
const int INF = 1e9;

int n;
string s;
bitset<710> bisa[N][N]; // l, r, len = bisa
int dp[N][N];
vector <int> faktor[N];

int pref[N][N]; // id-awal, i-th pref
bitset<710> cekpref[N][N];

void make_pref(int id0){
    int j = 0;
    for (int i=1;i+id0<n;i++){
        while (s[i + id0] != s[j + id0] && j != 0) j = pref[id0][j - 1];
        if (s[i + id0] == s[j + id0]) j++;
        pref[id0][i] = j;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i=1;i<=n;i++){
        for (int j=1;j<i;j++){
            if (i % j == 0){
                faktor[i].pb(j);
            }
        }
    }
    for (int i=0;i<n;i++){
        make_pref(i);
        for (int j=i;j<n;j++){
            int cur = j - i + 1;
            while (cur){
                cekpref[i][j][cur] = 1;
                cur = pref[i][cur - 1];
            }
        }
    }
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            bisa[i][j][j - i + 1] = 1;
            dp[i][j] = j - i + 1;
        }
    }
    for (int len=2;len<=n;len++){
        for (int i=0;i+len-1<n;i++){
            int j = i + len - 1;
            for (int k : faktor[len]){
                if (cekpref[i][j][k] && bisa[i][j - k][k]){
                    bisa[i][j][k] = 1;
                    dp[i][j] = min(dp[i][j], dp[i][i + k - 1]);
                }
            }
            for (int mid=i;mid<j;mid++){
                dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
            }
        }
    }

    cout << dp[0][n - 1] << el;

    return 0;
}