#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<int> c(n), d(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  vector<int> dif_1(n - 1), dif_2(n - 1);
  for (int i = 0; i < n - 1; i++) {
    dif_1[i] = c[i + 1] - c[i];
    dif_2[i] = d[i + 1] - d[i];
  }
  sort(dif_1.begin(), dif_1.end());
  sort(dif_2.begin(), dif_2.end());
  cout << (c[0] == d[0] && dif_1 == dif_2 ? "Yes" : "No") << '\n';

  return 0;
}
