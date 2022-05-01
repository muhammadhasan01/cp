#include <bits/stdc++.h>

using namespace std;
 
int C(int n, int k) {
    int res = 1;
    if (k > n - k)
    k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
     
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l, r;
    cin >> l >> r;
    assert(l <= r);
    int up = r;
    for (int i = l; i <= up; i++) {
        for (int it = 0; it < up - i; it++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << C(i, j) << " \n"[j == i];
        }
    }
    
    
    return 0;
}
/**

      1 
     1 1 
    1 2 1 
   1 3 3 1 
  1 4 6 4 1 
 1 5 10 10 5 1 
1 6 15 20 15 6 1
**/