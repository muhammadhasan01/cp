#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set X;

int main() {
    cout<<*X.find_by_order(1)<<endl;          // array index ke-1
    cout<<(end(X)==X.find_by_order(6))<<endl; // end(X) = pointer
    cout<<X.order_of_key(400)<<endl;          // idx lower_bound 400
}