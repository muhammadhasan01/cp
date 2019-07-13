#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int t = 1,n,m;
  string id;
    n = 3, m = 2;
    id = "A";
    string ids[n];
    int rank[3][n],score[3],pos;
    for(int i = 0; i < n; i++){
    cin >> ids[i];
    for(int j = 0; j < 3; j++){
      cin >> rank[j][i];
      if(ids[i] == id)
      {score[j] = rank[j][i];}
     }
    }
    int c;
    for(int j = 2; j >= 0;j--){
      c = 0;
      for(int i = 0; i < n ;i++){
      if(score[j] >= rank[j][i]){
        c+=1;}
      cout << c << " " << score[j];
      cout << " " << rank[j][i] << endl;
      if(n-c+1 == m){c = -1;
    break;}
    }
    if(c == -1){break;}
    }
    if(c == -1){
    cout << "YA" << endl;}
    else{cout << "TIDAK" << endl;}
  return 0;
}
// 3 : 1,2,3,4,5,6,7