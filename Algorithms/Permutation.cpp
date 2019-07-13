#include <bits/stdc++.h>
using namespace std;

void swap(char *x, char *y){
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void p(char *x, int l, int r){
  if(l == r){
    cout << x << endl;
  } else {
    for(int i = l; i <= r; i++){
      swap(x[l],x[i]);
      p(x,l+1,r);
      swap(x[i],x[l]);
    }
  }
}

int main(){
  char str[] = "ABCDE";
  p(str,0,4);
  
  /*
  ABC => ACB 1,2,3
  BAC => BCA
  CBA => CAB
  */
  return 0;
 }