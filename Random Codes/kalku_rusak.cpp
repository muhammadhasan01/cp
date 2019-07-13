#include <iostream>
using namespace std;

int main(){
  int inp,n;
  cin >> inp;
  while(inp--){
  cin >> n;
  if(n == 1){
    cout << 1 << endl;
  } else {
  cout << n*n*n - (n-2)*(n-2)*(n-2) << endl;}
  }
  return 0;
}