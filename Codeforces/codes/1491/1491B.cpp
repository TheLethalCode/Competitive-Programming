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
        int n, u, v, maD = 0;
        cin >> n >> u >> v;
        vector< int > V(n);
        for (int i = 0; i < n; i++) {
            cin >> V[i];
            if (i) {
                maD = max(maD, abs(V[i] - V[i-1]));
            }
        }
        if (!maD) {
            cout << min(u + v, 2 * v) << '\n';
        } else if (maD == 1) {
            cout << (u <= v? u : v)<< '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}