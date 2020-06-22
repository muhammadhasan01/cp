#include <bits/stdc++.h>

using namespace std;

int a[30], b[30];
vector<int> v[6];

void reset() {
    for (int i = 0; i < 24; i++) {
        b[i] = a[i];
    }
}
void check() {
    for (int i = 0; i < 24; i++) {
        if (i % 4 == 3) continue;
        if (b[i] != b[i + 1]) return;
    }
    puts("YES");
    exit(0);
}

void getz(vector<int> x) {
    reset();
    for (int i = 0; i < 8; i++) {
        b[x[(i + 2) % 8]] = a[x[i]];
    }
    check();
    reset();
    for (int i = 0; i < 8; i++) {
        b[x[i]] = a[x[(i + 2) % 8]];
    }
    check();
}

void BF() {
    v[0] = {1, 3, 5, 7, 9, 11, 24, 22}; // OK
    v[1] = {2, 4, 6, 8, 10, 12, 23, 21}; // OK
    v[2] = {3, 4, 17, 19, 10, 9, 16, 14}; // OK
    v[3] = {1, 2, 18, 20, 12, 11, 15, 13}; // OK
    v[4] = {13, 14, 5, 6, 17, 18, 21, 22}; // OK
    v[5] = {15, 16, 7, 8, 19, 20, 23, 24}; // OK;
    for (int i = 0; i < 6; i++) {
        for (auto& e : v[i]) e--;
    }
    for (int i = 0; i < 6; i++) {
        getz(v[i]);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 24; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    BF();
    puts("NO");

    return 0;
}