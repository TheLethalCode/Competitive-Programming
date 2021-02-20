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
        vector< pair< int, int > > R(10, {25000, 0}), C(10, {25000, 0});
        vector< string > V;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                int val = s[j] - '0';
                R[val].fi = min(R[val].fi, i);
                C[val].fi = min(C[val].fi, j);
                R[val].se = max(R[val].se, i);
                C[val].se = max(C[val].se, j);
            }
            V.pb(s);
        }
        vector< int > ans(10);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = V[i][j] - '0';
                int Rarea = max(i, n-1-i) * max(C[val].se - j, j - C[val].fi);
                int Carea = max(j, n-1-j) * max(R[val].se - i, i - R[val].fi);
                ans[val] = max(ans[val], max(Rarea, Carea));
            }
        }
        for (int v : ans) {
            cout << v << ' ';
        }
        cout << '\n';
    }
}