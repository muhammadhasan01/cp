#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto dismiss = [&]() {
        puts("NO");
        exit(0);
    };

    string str;
    cin >> str;
    string s = str;
    sort(s.begin(), s.end());
    if (s[0] != 'a') {
        dismiss();
    }
    int n = s.length();
    for (int i = 1; i < n; i++) {
        if (s[i] - s[i - 1] > 1) {
            dismiss();
        }
    }
    char cur = 'a';
    for (int i = 0; i < n; i++) {
        if (str[i] > cur) {
            dismiss();
        }
        if (str[i] == cur) {
            cur++;
        }
    }
    puts("YES");    

    return 0;
}