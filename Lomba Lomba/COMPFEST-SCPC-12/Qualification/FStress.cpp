#include <bits/stdc++.h>

using namespace std;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5;
const int K = 1e6;

int main () {
    srand(time(NULL));
    ofstream f;
    f.open("input.in");
    f << N << ' ' << N << '\n';
    for (int i = 0; i < N; i++) {
        f << rng32() % N + 1 << (i == N - 1 ? '\n' : ' ');
    }
    for (int i = 0; i < N; i++) {
        f << rng32() % K + 1 << '\n';
    }
    f.close();
    return 0;
}