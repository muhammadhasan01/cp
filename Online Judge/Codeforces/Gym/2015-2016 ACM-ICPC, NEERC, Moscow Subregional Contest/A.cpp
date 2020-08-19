#include <bits/stdc++.h>

using namespace std;

long long b;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> b; --b;
    vector<long long> div;
    for (long long i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            div.emplace_back(i);
            if (i * i != b) div.emplace_back(b / i);
        }
    }
    sort(div.begin(), div.end());
    int len = div.size();
    for (int i = 0; i < len; i++) {
        cout << div[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}