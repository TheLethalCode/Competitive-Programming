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
        int n;
        string x;
        cin >> n >> x;
        int v[2][2];
        memset(v, 0, sizeof v);
        for (int i = 1; i <= n; i++) {
            v[i&1][(x[i-1]-'0') % 2]++;
        }
        int ok = v[n&1][n&1];
        if (n & 1) {
            cout << (ok?1:2) << '\n';
        } else {
            cout << (ok?2:1) << '\n';
        }
    }
}