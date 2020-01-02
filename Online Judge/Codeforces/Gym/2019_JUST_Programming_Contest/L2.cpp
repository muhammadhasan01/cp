#include <bits/stdc++.h>

using namespace std;

// source : https://github.com/MohamedAhmed04/Competitive-programming/blob/master/IOI/IOI%202010-Quality%20of%20living.cpp

int Q[3005][3005];

int rectangle(int R, int C, int H, int W)
{
    int smaller[R+1][C+1] , bigger[R+1][C+1] , arr[R+1][C+1];
    //make grid 1-indexed
    memset(smaller , 0 , sizeof(smaller)) ;
    memset(bigger , 0 , sizeof(bigger)) ;
    for(int i = 1 ; i <= R ; ++i)
    {
        for(int j = 1 ; j <= C ; ++j)
            arr[i][j] = Q[i-1][j-1] ;
    }
    //make binary search and return minimum answer
    int l = 1 , r = R*C , ans = R*C ;
    while(l <= r)
    {
        int mid = (l + r) / 2 ;
        //prepare prefix array
        for(int i = 1 ; i <= R ; ++i)
        {
            int s = 0 , b = 0 ;
            for(int j = 1 ; j <= C ; ++j)
            {
                smaller[i][j] = s + smaller[i-1][j];
                if(arr[i][j] < mid)
                    smaller[i][j]++ , ++s;
                bigger[i][j] = b + bigger[i-1][j] ;
                if(arr[i][j] > mid)
                    bigger[i][j]++ , ++b;
            }
        }
        //loop on all possible rectangles if size H*W.
        bool t = false ;
        for(int i = 1 ; i <= R-H+1 ; ++i)
        {
            for(int j = 1 ; j <= C-W+1 ; ++j)
            {
                int s = smaller[i+H-1][j+W-1] - smaller[i+H-1][j-1] - smaller[i-1][j+W-1] + smaller[i-1][j-1] ;
                int b = bigger[i+H-1][j+W-1] - bigger[i+H-1][j-1] - bigger[i-1][j+W-1] + bigger[i-1][j-1] ;
                if(s >= b)
                    t = true ;
                int n = R*C ;
                if(s == b && s <= n/2 && b <= n/2)
                    ans = min(ans , mid) ;
            }
        }
        if(t == true)
            r = mid-1 ;
        else
            l = mid+1 ;
    }
    return ans ;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, h, w;
  cin >> n >> m >> h >> w;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> Q[i][j];
    }
  }
  cout << rectangle(n, m, h, w) << '\n';

  return 0;
}
