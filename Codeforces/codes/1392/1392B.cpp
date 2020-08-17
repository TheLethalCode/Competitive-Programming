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
    while(t--) {
        lli n, k;
        cin >> n >> k;
        k &= 1;
        vector< lli > v(n);
        lli ma = -mod, mi = mod;
        FOR (i, n) {
            cin >> v[i];
            ma = max(ma, v[i]);
            mi = min(mi, v[i]);
        }
        FOR (i, n) {
            if (k) {
                v[i] = ma - v[i];
            } else {
                v[i] = v[i] - mi;
            }
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
}