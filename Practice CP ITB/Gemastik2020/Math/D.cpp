#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> answer;
    vector<bool> not_prime(n + 1);
    for (int i = 2; i <= n; i++) {
        if (not_prime[i]) continue;
        int cur = i;
        while (cur <= n) {
            answer.emplace_back(cur);
            cur *= i;
        }
        for (int j = i + i; j <= n; j += i) {
            not_prime[j] = 1;
        }
    }
    int len = answer.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << answer[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}