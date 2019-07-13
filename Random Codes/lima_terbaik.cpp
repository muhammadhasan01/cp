#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int inp;
  cin >> inp;
  while(inp--){
  int x;
  cin >> x;
  int a[x];
  for(int i = 0; i < x;i++){
    cin >> a[i];
  }
  sort(a,a+x);
  int c = 0;
  for(int i = x-5; i < x; i++){
    c += a[i];
  }
  cout << c << endl;}
  return 0;
}