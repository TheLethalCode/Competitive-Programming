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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        int a1 = a, a2 = a, b1 = b, b2 = b, n1 = n, n2 = n;
        int k1 = min(n1, a1 - x);
        a1 -= k1, n1 -= k1;
        b1 -= min(n1, b1 - y);

        int k2 = min(n2, b2 - y);
        b2 -= k2, n2 -= k2;
        a2 -= min(n2, a2 - x);
        cout << min(1LL * a1 * b1, 1LL * a2 * b2) << '\n'; 
    }
}