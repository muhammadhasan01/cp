#include <bits/stdc++.h>

using namespace std;

const int N = 15;

long long nine[N];

string add_one(string x) {
    long long num = stoll(x);
    num += 1;
    return to_string(num);
}

long long rec(string s) {
    int n = s.size();
    if (n % 2 == 1) {
        return nine[n] - stoll(s);
    }
    string x = s.substr(0, n / 2);
    string y = s.substr(n / 2, n / 2);
    if (stoll(x) >= stoll(y)) {
        long long dif = stoll(x) - stoll(y);
        return dif + 1 + rec(x);
    }
    x = add_one(x);
    long long cur = nine[n / 2] - stoll(y) + 1 + stoll(x);
    return cur + 1 + rec(x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    nine[0] = 1;
    for (int i = 1; i < N; i++) {
        nine[i] = nine[i - 1] * 10;
    }
    for (int i = 0; i < N; i++) {
        nine[i]--;
    }
    string str;
    cin >> str;
    cout << rec(str) << '\n';

    return 0;
}