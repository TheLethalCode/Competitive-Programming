#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

string succ(string l) {
    int i = l.size() - 1;
    while (l[i] != '0') {
        l[i] = '0';
        i--;
    }
    l[i] = '1';
    return l;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;
    if (l == r) {
        cout << l << '\n';
    } else if (l[0] != r[0]) {
        cout << string(n, '1') << '\n';
    } else if (r[n-1] == '1' || succ(l) == r) {
        cout << r << '\n';
    } else {
        cout << r.substr(0, n-1) + "1" << '\n';
    }
}