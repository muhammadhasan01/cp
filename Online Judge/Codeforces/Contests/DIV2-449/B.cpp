#include <bits/stdc++.h>

using namespace std;

int k;
long long p;
long long ans;

void add(int x) {
  string now = to_string(x);
  string temp = now;
  reverse(temp.begin(), temp.end());
  now = now + temp;
  long long res = 0;
  for (int i = 0; i < (int) now.size(); i++) {
    res = (res * 10) + (now[i] - '0');
  }
  ans = (ans + res) % p;
}

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> k >> p;
  // add(k);
  for (int i = 1; i <= k; i++) {
    add(i);
  }
  cout << ans << '\n';

  return 0;
}