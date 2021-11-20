#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [&](auto& lhs, auto& rhs) {
        return lhs.first * rhs.second  < rhs.first * lhs.second;
    });
    long double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (long double) v[i].first / v[i].second;
    }
    long double mini = (long double) v[0].first / v[0].second;
    long double maxi = (long double) v[n - 1].first / v[n - 1].second;
    cout << fixed << setprecision(12) << mini << ' ' << maxi << ' ' << sum << '\n';
    return 0;
}