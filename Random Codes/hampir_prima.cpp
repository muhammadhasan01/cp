#include <iostream>
using namespace std;

int isPrima(int n){
  if(n == 1){return 0;}
  else if(n == 2){return 1;}
  else {
   for(int i = 2; i*i <= n; i++){
   if(n%i == 0){
     return 0;
   }
  }
  return 1;
}}

int hampirPrima(int n){
  int c = 0;
  if(n <= 3){return 0;}
  else{
  for(int i = 2; i*i <= n; i++){
    if(n%i == 0){
       if(isPrima(n/i)){
         return 1;
       } else {
         return 0;
       }
      }
    if(i > 2){ i += 1;}
  }
  return 0;
  }
}

int main(){
  int inp;
  cin >> inp;
  while(inp--){
  int a,b,c = 0;
  cin >> a >> b;
  for(int i = a; i <= b; i++){
    if(hampirPrima(i)){
    c+=1;}
  }
  cout << c << endl;}
  return 0;
}