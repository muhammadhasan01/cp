#include <bits/stdc++.h>

using namespace std;

const int lastTime = 23 * 60 + 59;

int a, ta, b, tb;
string str;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> ta >> b >> tb;
    cin >> str;
    int curTime = 5 * 60;
    vector<pair<int, int>> v;
    while (curTime <= lastTime) {
        v.emplace_back(curTime, curTime + tb);
        curTime += b;
    }
    int depTime = 60 * stoi(str.substr(0, 2)) + stoi(str.substr(3, 2));
    int arrTime = depTime + ta;
    int ans = 0;
    for (auto& e : v) {
        if (e.first < arrTime && e.second > depTime)
            ++ans;
    }
    cout << ans << '\n';

    return 0;
}