#include <bits/stdc++.h>

using namespace std;
 
const int N = 1005;

int magicSquare[N][N];

// A function to generate odd sized magic squares
void generateSquare(int n)
{
 
    // set all slots as 0
    memset(magicSquare, 0, sizeof(magicSquare));
 
    // Initialize position for 1
    int i = n / 2;
    int j = n - 1;
 
    // One by one put all values in magic square
    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) // 3rd condition
        {
            j = n - 2;
            i = 0;
        }
        else {
            // 1st condition helper if next number
            // goes to out of square's right side
            if (j == n)
                j = 0;
 
            // 1st condition helper if next number
            // is goes to out of square's upper side
            if (i < 0)
                i = n - 1;
        }
        if (magicSquare[i][j]) // 2nd condition
        {
            j -= 2;
            i++;
            continue;
        }
        else
            magicSquare[i][j] = num++; // set number
 
        j++;
        i--; // 1st condition
    }
}
 
// Driver code
int main()
{
 
    // Works only when n is odd
    int n = 7;
    cin >> n;
    generateSquare(n);
    vector<vector<int>> a(n, vector<int>(n));
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;
            if (s == "X") {
                ans.emplace_back(magicSquare[i][j]);
            } else {
                a[i][j] = stoi(s);
            }
        }
    }
    int len = ans.size();
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
    return 0;
}
 
// This code is contributed by rathbhupendra