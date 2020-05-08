#include <bits/stdc++.h>

using namespace std;



int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  vector<long double> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<long double> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  long double s = 0, e = 0;
  for (int i = 0; i < n; i++) {
    s += (v[i] - 50.8333) * (v[i] - 57.3333);
    e += w[i];
  }
  e = 1;
  cout << fixed << setprecision(10) << s / e << '\n';
  
  return 0;
}