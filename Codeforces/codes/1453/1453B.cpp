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
        vector< lli > v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        lli ans = 0, maxdiff = 0;
        for (int i = 1; i < n; i++) {
            ans += abs(v[i] - v[i-1]);
            lli val = abs(v[i] - v[i-1]);
            if (i - 1) {
                val += abs(v[i-1] - v[i-2]) - abs(v[i] - v[i-2]);
            }
            maxdiff = max(maxdiff, val);
        }
        maxdiff = max(maxdiff, abs(v[n-1] - v[n-2]));
        cout << ans - maxdiff << '\n';
    }
}