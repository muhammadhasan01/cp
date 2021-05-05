#include <bits/stdc++.h>

using namespace std;

bool is_yy_mm(int x, int y) {
    return (0 < y) && (y <= 12);
}

bool is_mm_yy(int x, int y) {
    return is_yy_mm(y, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int x = stoi(str.substr(0, 2));
    int y = stoi(str.substr(2, 2));
    bool yy_mm = is_yy_mm(x, y);
    bool mm_yy = is_mm_yy(x, y);
    string result;
    if (yy_mm && mm_yy) {
        result = "AMBIGUOUS";
    } else if (yy_mm) {
        result = "YYMM";
    } else if (mm_yy) {
        result = "MMYY";
    } else {
        result = "NA";
    }
    cout << result << '\n';

    return 0;
}