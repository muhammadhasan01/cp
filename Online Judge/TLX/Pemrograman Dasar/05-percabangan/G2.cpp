#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    int distance(Point& other) {
        return abs(x - other.x) + abs(y - other.y);
    }
};

istream& operator>>(istream& in, Point& p) {
  in >> p.x >> p.y;
  return in;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Point p1, p2;
    cin >> p1 >> p2;
    cout << p1.distance(p2) << '\n';
    
    return 0;
}