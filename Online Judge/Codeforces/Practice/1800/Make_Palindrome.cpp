#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
string s;
char alf[30];
char ans[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 26; i++) {
    alf[i] = char(int('a') + i);
  }
  vector<int> v(30);
  cin >> s;
  for (auto e : s) {
    v[e - 'a']++;
  }
  int odd = ((int) s.size() & 1);
  vector<int> k;
  for (int i = 0; i < 26; i++) {
    if (v[i] & 1) k.push_back(i);
  }
  int len = k.size() / 2;
  int rem = -1;
  if (odd) {
    rem = k[len];
    k.erase(k.begin() + len);
  }
  for (int i = 0; i < len; i++) {
    v[k[i]]++;
    v[k[i + len]]--;
  }
  int lenz = 0;
  for (int i = 0; i < 26; i++) {
    if (v[i] > 0) {
      for (int j = 0; j < v[i] / 2; j++) {
        ans[++lenz] = alf[i];
      }
    }
  }
  if (odd) ans[++lenz] = alf[rem];
  for (int i = 25; i >= 0; i--) {
    if (v[i] > 0) {
      for (int j = 0; j < v[i] / 2; j++) {
        ans[++lenz] = alf[i];
      }
    }
  }
  for (int i = 1; i <= lenz; i++) {
    cout << ans[i];
  }
  cout << '\n';

  return 0;
}
