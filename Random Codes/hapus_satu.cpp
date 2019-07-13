#include <iostream>
using namespace std;

int main(){
  string a,b;
  cin >> a >> b;
  int x = a.length(),c = 1;
  for(int i = 0; i < x; i++){
  if(b == a.substr(0,i)+a.substr(i+1,x-i-1)){
  cout << "Tentu saja bisa!" << endl;
  c = 0;
  break;
  }
  }
  if(c){cout << "Wah, tidak bisa :(" << endl;}
  return 0;
}