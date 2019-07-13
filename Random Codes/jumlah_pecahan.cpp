#include <iostream>
#include <vector>
using namespace std;

int prime(int n){
  vector<int> v;
  int s = 3,c;
  v.push_back(2);
  v.push_back(3);
  if(n == 1){return v[0];}
  else if(n == 2){return v[1];}
  else {
    while(true){
    c = 1;
    s += 2;
    for(int i = 0; i < v.size();i++){
      if(s%v[i] == 0){
        c = 0;
        break;
      }
    }
    if(c){v.push_back(s);}
    if(n == v.size()){return s;}
    }
  }
}
int main(){
  int inp;
  cin >> inp;
  while(inp--){
  int a;
  cin >> a;
  cout << prime(a) << endl;
  }
  return 0;
}