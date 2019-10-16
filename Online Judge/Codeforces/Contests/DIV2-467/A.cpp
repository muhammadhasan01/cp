#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    set<int> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] > 0) {
            s.insert(a[i]);
        }
    }
    cout << s.size() << '\n';


    return 0;
}
