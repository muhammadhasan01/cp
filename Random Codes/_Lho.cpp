#include <iostream>
using namespace std;

int main(){
  int inp;
  cin >> inp;
  while(inp--){
  string a;
  cin >> a;
  int c,m = 0;
  for(int i = 0; i < a.length();i++){
      if(a.substr(i,3) == "lho"){
        c = 0;
        int j = i+2;
        while(a[j] == 'o'){
          j++;
          c++;
        }
        if(a[j] != '?'){
          c = 0;
        } else if(m < c){
          m = c;
        }
        i = j;
      }
  }
  cout << m;
  if(inp != 0){
    cout << endl;}}
  return 0;
}