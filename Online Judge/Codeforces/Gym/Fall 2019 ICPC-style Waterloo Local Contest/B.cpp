#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;

long long K;

bool checkSquare(long long x) {
    long long l = 1, r = INF, at = 1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (mid * mid <= x) {
            l = mid + 1;
            at = mid;
        } else {
            r = mid - 1;
        }
    }
    return (at * at == x);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    vector<long long> answer;
    for (long long i = 1; i * i <= K; i++) {
        long long res = K - i * i;
        if (checkSquare(res)) {
            answer.emplace_back(-i * i);
        }
        if (K % i == 0) {
            long long cur = K / i - i;
            if (cur % 2 == 1) continue;
            if (cur == 0) continue;
            cur /= 2;
            answer.emplace_back(cur * cur);
            answer.emplace_back(-(cur * cur + K));
        }
    }
    sort(answer.begin(), answer.end());
    answer.resize(unique(answer.begin(), answer.end()) - answer.begin());
    int len = answer.size();
    cout << len << "\n";
    for (int i = 0; i < len; i++) {
        cout << answer[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}