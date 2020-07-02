#include <bits/stdc++.h>

using namespace std;

const int N = 105 + 5;

int n;
int cnt[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int sum = 0;
  vector<int> v;
  for (int i = 1; i <= 100; i++) {
    sum += cnt[i];
    if (cnt[i] > 0) v.push_back(i);
  }
  if (sum & 1) {
    cout << "NO" << '\n';
    return 0;
  }
  int len = v.size();
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (cnt[v[i]] == cnt[v[j]] && cnt[v[i]] == sum / 2) {
        cout << "YES" << '\n';
        cout << v[i] << " " << v[j] << '\n';
        return 0;
      }
    }
  }
  cout << "NO" << '\n';

  return 0;
}