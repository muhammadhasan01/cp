 #include<bits/stdc++.h>
 using namespace std;

string s;

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     cin >> s;
     int n = s.size();
     int k1 = 0, k2 = 0;
     for(auto e:s){
         if(e == '-'){
             k1++;
         }else{
             k2++;
         }
     }
     if(k2 == 0){
         puts("YES");
     }else{
         if(k1 % k2 == 0){
             puts("YES");
         }else{
             puts("NO");
         }
     }

     return 0;
 }
