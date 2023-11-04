#include <bits/stdc++.h>

using namespace std;

const int K = 3;

int a[K][K];
int b[K][K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            b[i][j] = a[j][i];
        }
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            cout << b[i][j] << " \n"[j == K - 1];
        }
    }
    
    return 0;
}