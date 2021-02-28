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
        int n;
        cin >> n;
        vector< int > bits(32);
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            bits[__builtin_clz(x)]++;;
        }
        lli ans = 0;
        for (int i = 0; i < 32; i++) {
            ans += 1LL * bits[i] * (bits[i] - 1) / 2;
        }
        cout << ans << '\n';
    }
}