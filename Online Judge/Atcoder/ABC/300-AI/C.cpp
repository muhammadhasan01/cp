#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H, W;
    cin >> H >> W;
    
    vector<string> grid(H);
    for (int i = 0; i < H; i++){
        cin >> grid[i];
    }
    
    int N = min(H, W);
    // S[n] will store the number of crosses of size n (n from 1 to N)
    vector<int> S(N+1, 0);
    
    // Helper lambda to safely get grid cell (using 0-indexing).
    auto getCell = [&](int i, int j) -> char {
        if(i < 0 || i >= H || j < 0 || j >= W)
            return '.';
        return grid[i][j];
    };
    
    // Iterate over all possible centers (i, j)
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if(getCell(i, j) != '#') continue;
            // Try to grow a cross of increasing size.
            for (int n = 1; n <= N; n++){
                bool armsValid = true;
                // Check the four arms for every d from 1 to n.
                for (int d = 1; d <= n; d++){
                    if(getCell(i+d, j+d) != '#' ||
                       getCell(i+d, j-d) != '#' ||
                       getCell(i-d, j+d) != '#' ||
                       getCell(i-d, j-d) != '#'){
                        armsValid = false;
                        break;
                    }
                }
                if(!armsValid) break;  // Cannot extend further for larger n.
                
                // Check extension condition: at least one of the four extension cells must be '.'
                bool extensionCondition = false;
                if(getCell(i+n+1, j+n+1) == '.') extensionCondition = true;
                if(getCell(i+n+1, j-n-1) == '.') extensionCondition = true;
                if(getCell(i-n-1, j+n+1) == '.') extensionCondition = true;
                if(getCell(i-n-1, j-n-1) == '.') extensionCondition = true;
                
                if(extensionCondition){
                    S[n]++;
                }
                // Note: Even if the extension condition is not satisfied,
                // the arms still exist so we try a larger cross.
            }
        }
    }
    
    // Print S[1] through S[N] separated by spaces.
    for (int n = 1; n <= N; n++){
        cout << S[n] << (n == N ? "\n" : " ");
    }
    
    return 0;
}
