#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

int n;
set<int> primes;
bool vis[N];
bool notPrime[N];
vector<int> primeFactors[N];

int main() { 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 2; i < N; i++) {
    if (notPrime[i] == 0) {
      primes.insert(i);
      primeFactors[i].push_back(i);
      for (int j = i + i; j < N; j += i) {
        notPrime[j] = 1;
        primeFactors[j].push_back(i);
      }
    }
  }
  cin >> n;
  bool ok = false;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (ok) {
      cout << (*primes.begin()) << ' ';
      primes.erase(primes.begin());
      continue;
    }
    if (vis[x]) {
      ok = true;
      while (vis[x]) x++;
      cout << x << " ";
      for (auto e : primeFactors[x]) {
        primes.erase(e);
      }
    } else {
      cout << x << " ";
      for (auto e : primeFactors[x]) {
        primes.erase(e);
        for (int j = e; j < N; j += e) vis[j] = 1;
      }
    }
  }
  cout << '\n';

  return 0;
}