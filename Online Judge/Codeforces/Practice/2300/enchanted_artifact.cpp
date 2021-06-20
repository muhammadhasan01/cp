#include <bits/stdc++.h>

using namespace std;

const int N = 300;

int ask(string s) {
    cout << s << endl;
    int ret;
    cin >> ret;
    if (ret == 0) {
        exit(0);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num_a = N - ask(string(N, 'a'));
    int num_b = N - ask(string(N, 'b'));
    int n = num_a + num_b;
    string s(n, 'a');
    for (int i = 0; i < n - 1; i++) {
        s[i] = 'b';
        if (ask(s) > num_b) {
            s[i] = 'a';
        } else {
            num_b--;
        }
    }
    if (num_b) {
        s[n - 1] = 'b';
    }
    ask(s);

    return 0;
}