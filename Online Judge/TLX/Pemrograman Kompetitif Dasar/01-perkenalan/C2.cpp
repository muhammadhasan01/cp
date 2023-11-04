#include <iostream>
using namespace std;

int main() {
  string a, b, c;
  int inp;
  cin >> a >> inp;
  while (inp--) {
    cin >> c;
    int x = a.length() - 1;  // 6
    int y = c.length() - 1;
    int pos = a.find("*");  // 3
    if (a != "*") {
      if (x - 1 <= y) {
        b = c.substr(0, pos) + "*" + c.substr(y - (x - pos - 1), x - pos);
        if (a == b) {
          cout << c << endl;
        }
      }
    } else {
      cout << c << endl;
    }
  }
  return 0;
}