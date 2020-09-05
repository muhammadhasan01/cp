#include <bits/stdc++.h>

using namespace std;

const long long M = 104206969;

const vector<int> dates = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

long long countLeapYear(long long x) {
    if (x < 0) return 0LL;
    long long ret = (x / 4) - (x / 100) + (x / 400) + 1;
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long val_year = 0;
    for (int i = 1; i <= 12; i++) {
        int x = dates[i - 1];
        string I = to_string(i);
        for (int j = 1; j <= x; j++) {
            string val = I + to_string(j);
            val_year = (val_year + stoi(val)) % M;
        }
    }
    long long val_leap_year = (val_year + 229) % M;
    long long A, B;
    cin >> A >> B;
    long long leapYears = (countLeapYear(B) - countLeapYear(A - 1));
    long long normYears = ((B - A + 1) - leapYears);
    leapYears %= M, normYears %= M;
    long long ans = (leapYears * val_leap_year) % M;
    ans = (ans + val_year * normYears) % M;
    cout << (ans % M + M) % M << "\n";

    return 0;
}