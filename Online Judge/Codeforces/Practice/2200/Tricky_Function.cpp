#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;

const ll INF = 2e18;

int n;
vector<point> p, t;
ll bestDist;

bool compSecond(const point& a, const point& b) {
    return (a.second < b.second);
}

ll distance(point a, point b) {
    a.first -= b.first;
    a.second -= b.second;
    return (a.first * a.first) + (a.second * a.second);
}

void findClosestPoint(int s, int e) {
    if (e - s <= 3) {
        for (int i = s; i < e; i++) {
            for (int j = i + 1; j < e; j++) {
                bestDist = min(bestDist, distance(p[i], p[j]));
            }
        }
        sort(p.begin() + s, p.begin() + e, compSecond);
        return;
    }
    int mid = (s + e) >> 1;
    ll midx = p[mid].first;
    findClosestPoint(s, mid);
    findClosestPoint(mid, e);
    ll dist = sqrtl(bestDist) + 1;
    merge(p.begin() + s, p.begin() + mid, p.begin() + mid, p.begin() + e, t.begin(), compSecond);
    copy(t.begin(), t.begin() + e - s, p.begin() + s);
    int len = 0;
    for (int i = s; i < e; i++) {
        if (abs(p[i].first - midx) >= dist) continue;
        for (int j = len - 1; j >= 0 && p[i].second - t[j].second < dist; --j)
            bestDist = min(bestDist, distance(p[i], t[j]));
        t[len++] = p[i];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    p.resize(n), t.resize(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
        p[i] = make_pair(i + 1, sum);
    }
    sort(p.begin(), p.end());
    bestDist = INF;
    findClosestPoint(0, n);
    cout << bestDist << '\n';

    return 0;
}