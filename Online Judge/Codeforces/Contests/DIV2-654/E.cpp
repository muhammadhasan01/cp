#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n, p;
int a[N];
vector<int> answer;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        
    }
    cout << answer.size() << '\n';
    for (auto& e : answer) cout << e << " ";
    cout << '\n';

    return 0;
}