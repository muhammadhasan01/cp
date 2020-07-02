#include <bits/stdc++.h>

using namespace std;

int n;
int cx, cy;
string s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "? " << i << " " << n - i + 1 << " " << n << " " << n << endl;
        cin >> s;
        if (s != "YES") continue;
        cout << "? " << 1 << " " << 1 << " " << i << " " << n - i + 1 << endl;
        cin >> s;
        if (s != "YES") continue;
        cx = i, cy = n - i + 1;
        break;
    }
    string answer = "", result = "";
    int cur_x = 1, cur_y = 1;
    while (cur_x < cx || cur_y < cy) {
        if (cur_x == cx) {
            answer += "R";
            cur_y++;
            continue;
        } else if (cur_y == cy) {
            answer += "D";
            cur_x++;
            continue;
        }
        cout << "? " << cur_x << " " << cur_y + 1 << " " << n << " " << n << endl;
        cin >> s;
        if (s != "YES") {
            answer += "D";
            cur_x++;
        } else {
            answer += "R";
            cur_y++;
        }
    }
    cur_x = n, cur_y = n;
    while (cur_x > cx || cur_y > cy) {
        if (cur_x == cx) {
            result = "R" + result;
            cur_y--;
            continue;
        } else if (cur_y == cy) {
            result = "D" + result;
            cur_x--;
            continue;
        }
        cout << "? " << 1 << " " << 1 << " " << cur_x - 1 << " " << cur_y << endl;
        cin >> s;
        if (s == "YES") {
            result = "D" + result;
            cur_x--;
        } else {
            result = "R" + result;
            cur_y--;
        }
    }
    cout << "! " << answer << result << endl;

    return 0;
}