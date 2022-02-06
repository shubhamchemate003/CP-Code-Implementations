// src: https://codeforces.com/blog/entry/11080 + Benq Github

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Tree;

#define ook order_of_key
#define fbo find_by_order

void treeExample() {
    Tree t, t2;
    t.insert(8);
    auto it = t.insert(10).first;
    assert(it == t.lower_bound(9));
    assert(t.ook(10) == 1 && t.ook(11) == 2 && *t.fbo(0) == 8);
    t.join(t2); // assuming T < T2 or T > T2, merge t2 into t
}

// third thing is comparator
// use greater<int> for ascending order
// for storing duplicate values use pair<int, int>
// *s.fbo(k)
// s.ook(k)

signed main() {
#ifndef ONLINE_JUDGE
    freopen("../input1.txt", "r", stdin);
    freopen("../output1.txt", "w", stdout);
#endif

    return 0;
}