#include <bits/stdc++.h>
using namespace std;

int n;
int a[105], b[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int score = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            score += 3;
        } else if (a[i] == b[i]) {
            score++;
        }
    }
    cout << s


    return 0;
}
