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
        vector < int > v[n+1][n+1], a(n);
        FOR (i, n) {
            cin >> a[i];
        }
        for (int i = 2; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                v[a[i]][a[j]].pb(i);
            }
        }
        lli ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                ans += v[a[i]][a[j]].end() - upper_bound(v[a[i]][a[j]].begin(), v[a[i]][a[j]].end(), j);
            }
        }
        cout << ans << '\n';
    }
}