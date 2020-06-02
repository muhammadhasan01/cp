#include <bits/stdc++.h>

using namespace std;

string s;
long long ans;

bool isVowel(const char& CC) {
    for (auto e : "aiueo") {
        if (CC == e) return true;
    }
    return false;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    if (isVowel(s[n - 1]) && !isVowel(s[0])) {
        cout << 0 << '\n';
        return 0;
    }


    return 0;
}