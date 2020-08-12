// Author : donbasta
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int SZ = 1000;
const int MOD = 1e9 + 7;
const int N = 2e5;

vector<vector<bool>> ada;
vector<vector<int>> pre;
int pw[N + 5];
int n;

int modpow(int a, int b) {
  int ret = 1;
  while(b) {
    if(b & 1) ret = (1LL * ret * a) % MOD;
    a = 1LL * a * a % MOD;
    b >>= 1;
  }
  return ret;
}

int inv(int a) {
  return modpow(a, MOD - 2);
}

int calc(int a, int b) {
  int cnt = pw[pre[SZ][SZ]] - 1;
  int kiri = pre[a - 1][SZ];
  int kanan = pre[SZ][SZ] - pre[a][SZ];
  int atas = pre[SZ][b - 1];
  int bawah = pre[SZ][SZ] - pre[SZ][b];
  int timur_laut = atas - pre[a][b - 1];
  int tenggara = pre[SZ][SZ] - pre[a][SZ] - pre[SZ][b] + pre[a][b];
  int barat_daya = kiri - pre[a - 1][b];
  int barat_laut = pre[a - 1][b - 1];
  cnt = (1LL * cnt - pw[kiri]) % MOD;
  cnt = (1LL * cnt - pw[kanan]) % MOD;
  cnt = (1LL * cnt - pw[atas]) % MOD;
  cnt = (1LL * cnt - pw[bawah]) % MOD;
  cnt = (1LL * cnt + pw[timur_laut]) % MOD;
  cnt = (1LL * cnt + pw[tenggara]) % MOD;
  cnt = (1LL * cnt + pw[barat_laut]) % MOD;
  cnt = (1LL * cnt + pw[barat_daya]) % MOD;
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  pw[0] = 1;
  for(int i = 1; i <= N; i++) {
    pw[i] = (1LL * 2 * pw[i - 1]) % MOD;
  }

  int T;
  cin >> T;
  while(T--) {
    cin >> n;

    ada.assign(SZ + 1, vector<bool>(SZ + 1, false));
    pre.assign(SZ + 1, vector<int>(SZ + 1, 0));

    for(int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      ada[a][b] = true;
    }
    for(int i = 1; i <= SZ; i++) {
      for(int j = 1; j <= SZ; j++) {
        pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
        pre[i][j] += ada[i][j];
      }
    }
    int ans = 0;
    for(int i = 1; i <= SZ; i++) {
      for(int j = 1; j <= SZ; j++) {
        ans = (1LL * ans + calc(i, j)) % MOD;
      }
    }
    ans = (1LL * ans * inv(modpow(2, n))) % MOD;
    if(ans < 0)
      ans += MOD;
    cout << ans << '\n';
  }
  
  return 0;
}