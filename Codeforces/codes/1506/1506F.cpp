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

int solve(int r1, int c1, int r2, int c2) {
    int diff1 = r1 - c1, diff2 = r2 - c2;
    if (diff1 == diff2) {
        return !(diff1 & 1) * (r2 - r1);
    }
    diff1 += !(diff1 & 1);
    return (diff2 - diff1 + 1)/2;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector< pair< int, int > > v(n + 1);
        v[0] = {1, 1};
        for (int i = 1; i <= n; i++) {
            cin >> v[i].fi;
        }
        for (int i = 1; i <= n; i++) {
            cin >> v[i].se;
        }
        sort(v.begin(), v.end());
        lli ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += solve(v[i-1].fi, v[i-1].se, v[i].fi, v[i].se);
        }
        cout << ans << "\n";
    }
}