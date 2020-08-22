#include <bits/stdc++.h>

using namespace std;

const int MAX_DEPTH = 1e8;

int depth = 0;
long long a, b, c, d;

void hahe(int x) {
    ++depth;
    if (depth == MAX_DEPTH) return;
    hahe(x + 1);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> a >> b >> c >> d;
    int x = 1;
    hahe(x);
    cout << (a * c - b * d) << " " << (b * c + a * d) << 'i' << '\n';

    return 0;
}