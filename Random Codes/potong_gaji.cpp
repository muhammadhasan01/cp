#include <iostream>
using namespace std;

int main(){
  int inp;
  cin >> inp;
  while(inp--){
  int n,m,sum1 = 0,sum2 = 0,c=0;
  cin >> n >> m;
  int batas = -1;
  int arr[n];
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    sum1 += arr[i];
    if(arr[i] < m/n){
      sum2 += arr[i];
      c += 1;
    }
  }
  if(sum1 > m){
    batas = (m-sum2)/(n-c);
  }
  cout << batas;
  if(inp != 0){
    cout << endl;
  }
  }
  return 0;
}