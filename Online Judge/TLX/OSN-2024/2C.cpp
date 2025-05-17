#include <bits/stdc++.h>
using namespace std;

const int MAXN = 23;
int n, m;
bool grid[MAXN][MAXN];
bool valid[MAXN][MAXN];
int bacteria;

void input() {
    bacteria = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = (s[j] == '1');
            if (grid[i][j]) {
                bacteria++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int prod = n * m;
    input();
    int curwidth = 1;
    while (bacteria && curwidth < prod) {
        // Expand as much as possible
        int expansion = min(prod - curwidth, curwidth);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                valid[i][j] = false;
                if (!grid[(i + expansion * n - expansion) % n][j]) {
                    valid[i][j] = true;
                }
                if (!grid[i][(j + expansion * m - expansion) % m]) {
                    valid[i][j] = true;
                }
            }
        }
        cout << "AKSELERASI " << expansion << endl;
        input();
        // Take all valid bacteria
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (valid[i][j] && grid[i][j]) {
                    cout << "EKSPERIMEN " << i + 1 << " " << j + 1 << endl;
                    int xx;
                    cin >> xx;
                    grid[i][j] = false;
                    bacteria--;
                }
            }
        }
        curwidth += expansion;
    }

    return 0;
}
