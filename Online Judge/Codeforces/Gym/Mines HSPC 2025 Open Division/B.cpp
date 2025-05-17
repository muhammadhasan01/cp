#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    getline(cin, s);
    int n;
    cin >> n;
    vector<string> A, B;
    string rule;
    getline(cin, rule);
    for (int i = 0; i < n; i++) {
        getline(cin, rule);
        auto pos = rule.find('=');
        A.emplace_back(rule.substr(0, pos));
        B.emplace_back(rule.substr(pos + 1));
    }
    for (int step = 1; step <= 5000; step++) {
        bool applied = false;
        for (int i = 0; i < n; i++) {
            size_t pos = s.find(A[i]);
            if (pos != string::npos) {
                s = s.substr(0, pos) + B[i] + s.substr(pos + A[i].size());
                applied = true;
                if (s.size() > 255) {
                    cout << "Memory Limit Exceeded\n";
                    return 0;
                }
                break;
            }
        }
        if (!applied) {
            cout << s << '\n';
            return 0;
        }
        if (step == 5000) {
            for (int i = 0; i < n; i++) {
                if (s.find(A[i]) != string::npos) {
                    cout << "Time Limit Exceeded\n";
                    return 0;
                }
            }
            cout << s << '\n';
            return 0;
        }
    }

    return 0;
}
