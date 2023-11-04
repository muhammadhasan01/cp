#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    ordered_set st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        st.insert(s);
        cout << st.order_of_key(s) + 1 << '\n';
    }
    
    return 0;
}