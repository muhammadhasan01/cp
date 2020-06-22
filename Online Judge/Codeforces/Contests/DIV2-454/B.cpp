#include <bits/stdc++.h>

using namespace std;

const int N = 11;

char a[N + 5][N + 5];
int lx, ly, x, y;


void answer() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    exit(0);
}

void fill() {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (a[i][j] == '.') a[i][j] = '!';
        }
    }
    answer();
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = ' ';
        }
    }
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s); 
        for (int j = 0; j < (int) s.size(); j++) {
            a[i][j] = s[j];
        }
    }
    cin >> lx >> ly;
    lx--, ly--;
    lx %= 3, ly %= 3;
    x = 4 * lx, y = 4 * ly;
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            if (a[i][j] == '.') {
                fill();
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == '.') a[i][j] = '!';
        }
    }
    answer();

    return 0;
}