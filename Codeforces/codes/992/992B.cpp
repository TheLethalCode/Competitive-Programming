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
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    if (y % x) {
        cout << "0\n";
        return 0;
    }
    l = (l + x - 1) / x;
    r = r / x;
    y = y / x;
    int ans = 0;
    for (int i = 1; 1LL * i * i <= y; i++) {
        if (y % i == 0 && __gcd(i, y/i) == 1) {
            if (l <= i && i <= r && l <= y/i && y/i <= r) {
                ans += 1 + (i != y/i);
            }
        }
    }
    cout << ans << '\n';
}