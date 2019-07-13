#include <iostream>
using namespace std;

int swap(int &a,int &b){
  int temp = a;
  a = b;
  b = temp;
}
int main(){
  int a[] = {3,2,5,4,7,6,8,9,1};
  int akhir = 0;
  while(akhir != 8){
  for(int i = 8; i > akhir; i--){
    if(a[i] < a[i-1]){swap(a[i],a[i-1]);}
    if(i == akhir+1){akhir+=1;}
  }}
  for(int i = 0; i < 9; i++){
    cout << a[i] << " ";
  }
  return 0;
}