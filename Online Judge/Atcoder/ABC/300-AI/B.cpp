#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    
    // Read grid A and grid B.
    vector<string> A(H), B(H);
    for (int i = 0; i < H; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < H; i++) {
        cin >> B[i];
    }
    
    // Try every possible vertical shift s and horizontal shift t.
    // A vertical shift by s means that the new grid cell at row i becomes the original A[(i+s) % H].
    // Similarly, a horizontal shift by t means that the new grid cell at column j becomes the original A[][ (j+t) % W ].
    for (int s = 0; s < H; s++) {
        for (int t = 0; t < W; t++) {
            bool isEqual = true;
            // Check if after applying the shifts, every cell of A matches the corresponding cell of B.
            for (int i = 0; i < H && isEqual; i++) {
                for (int j = 0; j < W; j++) {
                    if (A[(i + s) % H][(j + t) % W] != B[i][j]) {
                        isEqual = false;
                        break;
                    }
                }
            }
            // If a match is found, output Yes and exit.
            if (isEqual) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    // If no valid (s,t) is found, output No.
    cout << "No" << endl;
    return 0;
}
