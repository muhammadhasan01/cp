#include <bits/stdc++.h>

using namespace std;

string s1, s2, s3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2 >> s3;
    int k = 11;
    char x = 'x';
    for (int i = 0; i < 10; i++) {
        if (s1[i] == '=') {
            for (int j = i; j < 10; j++) {
                if (s1[j] == 'H') {
                    x = s1[j]; k = j; break;
                } else if (s1[j] == 'T') {
                    x = s1[j]; k = j; break;
                } else if (s1[j] == 'P') {
                    x = s1[j]; k = j; break;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (s2[i] == '=') {
            for (int j = i; j < 10; j++) {
                if (s2[j] == 'H' && j < k) {
                    x = s2[j]; k = j; break;
                } else if (s2[j] == 'T' && j < k) {
                    x = s2[j]; k = j; break;
                } else if (s2[j] == 'P' && j < k) {
                    x = s2[j]; k = j; break;
                }
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (s3[i] == '=') {
            for (int j = i; j < 10; j++) {
                if (s3[j] == 'H' && j < k) {
                    x = s3[j]; k = j; break;
                } else if (s3[j] == 'T' && j < k) {
                    x = s3[j]; k = j; break;
                } else if (s3[j] == 'P' && j < k) {
                    x = s3[j]; k = j; break;
                }
            }
        }
    }
    if (k == 11) {
        puts("You shall pass!!!");
    } else {
        cout << x << '\n';
    }

    return 0;
}
