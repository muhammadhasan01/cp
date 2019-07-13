#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int inp;
  cin >> inp;
  while(inp--){
  int a[3];
  for(int i = 0; i < 3; i++){
    cin >> a[i];
  }
  if(a[0] == a[1]){
    cout << a[0] << endl;
  } else {
  if(a[1]-a[0] == a[2]-a[1]){
    cout << 3*a[1]-2*a[0] << endl;
  }
  if(a[1]*a[1] == a[2]*a[0]){
    cout << pow(a[1],3)/pow(a[0],2)<< endl;
  }
  }}
  return 0;
}