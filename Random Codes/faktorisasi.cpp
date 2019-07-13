#include <iostream>
using namespace std;

int main(){
  int a, i = 2, c = 0;
  cin >> a;
  if(a == 1){cout << a;}
  while(a != 1){
    if(a%i == 0){
      a = a/i;
      c += 1;
      if(a%i != 0){
        cout << i;
        if(c > 1){
          cout << "^" << c;
        }
        if(a != 1){
          cout << " x ";
        }
      }
    } else {
      c = 0;
      if(i!=2){
        i += 2;
      } else {
        i += 1;
      }
    }
  }
  cout << endl;
  return 0;
}