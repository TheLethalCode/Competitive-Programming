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
        vector< pair< int , int > > v(n + 1);
        vector< int > tm(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i].fi >> v[i].se;
        }
        for (int i = 1; i <= n; i++) {
            cin >> tm[i];
        }
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += tm[i] + v[i].fi - v[i-1].se;
            if (i != n) {
                cur = max(v[i].se, cur + (v[i].se - v[i].fi + 1)/2);
            }
        }
        cout << cur << '\n';
    }
}