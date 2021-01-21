#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <functional>
#include <tuple>
#include <cstring>
#include <cstring>
using namespace std;

typedef long long ll;

#define MAXN 51

// dp[number of rounds % 2][current index of x][current index of y] = probability
double dp[2][MAXN][MAXN];
// const double eps = 1e-8;

double solve(const int N /*size*/, const double p /*probabilty of a swap*/,
    const int X /*first item*/, const int Y/*second item*/,
    const int K/*turns*/) {
  memset(dp, 0, sizeof(dp));
  dp[0][X][Y] = 1;  // initial position
  const double p_no_corruption = N == 1? 1 : 1 - p;
  const double p_one_swap = N == 1 ? 0 : p / (N - 1);

  for (int k = 1; k <= K; ++k) {
    int p = (k - 1) & 1;  // previous row
    int c = k & 1; // current row
    bool change = false;
    for (int x = 0; x <= N; ++x) {
      for (int y = 0; y <= N; ++y) {
        dp[c][x][y] = 0;
        int possible_swaps = 0;
        if (x > 0) {
          // Step: x-1 => x
          possible_swaps++;
          if (y == x - 1) {
            // SWAP!
            dp[c][x][y] += dp[p][y][x] * p_one_swap;
          } else if (y == x) {
            dp[c][x][y] += dp[p][x - 1][y - 1] * p_one_swap;
          } else {
            dp[c][x][y] += dp[p][x - 1][y] * p_one_swap;
          }
        }
        if (x < N - 1) {
          // Step: x+1 => x
          possible_swaps++;
          if (y == x + 1) {
            // SWAP!
            dp[c][x][y] += dp[p][y][x] * p_one_swap;
          } else if (y == x) {
            dp[c][x][y] += dp[p][x + 1][y + 1] * p_one_swap;
          } else {
            dp[c][x][y] += dp[p][x + 1][y] * p_one_swap;
          }
        }
        if (y > 0 && y - 1 != x && y != x) {
          // Step: y-1 => y
          possible_swaps++;
          dp[c][x][y] += dp[p][x][y - 1] * p_one_swap;
        }
        if (y < N - 1 && y + 1 != x && y != x) {
          // Step: y+1 => y
          possible_swaps++;
          dp[c][x][y] += dp[p][x][y + 1] * p_one_swap;
        }
        // Step: no swap
        double p_no_swap = p_no_corruption
            + (N - 1 - possible_swaps) * p_one_swap;
        dp[c][x][y] += dp[p][x][y] * p_no_swap;

//        printf("%d %d %d = %.5lf\n", k, x, y, dp[c][x][y]);
        
      }
    }
    // if (fabs(dp[c][X][Y] - dp[p][X][Y]) < 1e-8) {
        //   break;
        // }
  }
  return dp[K & 1][Y][X];
}

int main() {
    freopen("assessment.in", "r", stdin);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    // N, p, x, y, k
    int N, x, y, k;
    double p;
    cin >> N >> p >> x >> y >> k;
    printf("Case %d: %.5lf\n", t + 1, solve(N, p, x, y, k));
  }

  return 0;
}
