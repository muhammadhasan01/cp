#include <iostream>
using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  int a[x];
  for(int i = 0; i < x; i++){
    cin >> a[i];
  }
  int foundIt = -1;
  for(int i = 0; i < x; i++){
    if(a[i] == y){
    foundIt = i;
    break;
    }
  }
  cout << foundIt << endl;
}