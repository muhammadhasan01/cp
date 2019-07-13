#include <bits/stdc++.h>
using namespace std;

int f(int N, int x[],int s, int &c,int memo[]){
  cout << N << " " << c << endl;
  c++;
  if(memo[N] != -1){
    return memo[N];
  }
  if(N == 0){return 0;}
  int best = N+1;
  for(int i = 0; i < s; i++){
    if(x[i] <= N){
      best = min(best,f(N-x[i],x,s,c,memo)+1);
    }
  }
  memo[N] = best;
  return memo[N];
}
int main () {
  int c[] = {2,4,5};
  int N = 17, d = 1;
  int memo[N+1];
  fill(memo,memo+N+1,-1);
  cout << f(N,c,sizeof(c)/sizeof(c[0]),d,memo) << endl;
}

/*
f(0) = 0
f(1) = 1
f(2) = f(1)+1 = 2
f(3) = f(2)+1 = 3
f(4) = 1
f(5) = f(4)+1
*/