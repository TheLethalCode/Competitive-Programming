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
    for (int z = 1; z <= t; z++) {
        int n;
        cin >> n;
        vector < int > v(n);
        FOR (i, n) {
            cin >> v[i];
        }
        int ans = 2, prev = 0;
        while (prev < n-1) {
            int k;
            for (k = prev + 1; k < n && v[k] - v[k-1] == v[prev+1] - v[prev]; k++) {
                continue;
            }
            ans = max(ans, k - prev);
            prev = k - 1;
        }
        cout << "Case #" << z << ": " << ans << '\n';
    }
}