#include <bits/stdc++.h>

using namespace std;

string inp;
char cc;

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<int> v;
  v.push_back(0);
  for (int i = 0; i <= 30; i++) v.push_back((1 << i));

  while (1) {
    cin >> inp;
    if (inp[0] != 's') exit(0);
    for (int i = 0; i <= 30; i++) {
      int left = v[i], right = v[i + 1];
      cout << "? " << left << " " << right << endl;
      cin >> cc;
      if (cc == 'y') continue;
      int ans = -1;
      int cleft = left++;
      while (left <= right) {
        int middle = (left + right) / 2;
        cout << "? " << cleft << " " << middle << endl;
        cin >> cc;
        if (cc == 'y') {
          left = middle + 1;
        } else if (cc == 'x') {
          ans = middle;
          right = middle - 1;
        } else {
          exit(0);
        }
      }
      cout << "! " << ans << endl; 
      break; 
    }
  }

  return 0;
}