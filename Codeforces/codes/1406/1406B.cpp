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
        vector< int > v[2];
        for (int x, i = 0; i < n; i++) {
            cin >> x;
            v[x >= 0].pb(x);
        }
        sort(v[0].begin(), v[0].end());
        sort(v[1].rbegin(), v[1].rend());
        lli ans = -1e18;
        for (int i = 0; i <= 5; i++) {
            if (i > v[0].size() || 5 - i > v[1].size()) {
                continue;
            }
            lli cp,temp = 1;
            for (int j = 0; j < 5 - i; j++) {
                temp *= v[1][j];
            }
            cp = temp;
            for (int j = 0; j < i; j++) {
                temp *= v[0][j];
            }
            ans = max(ans, temp);
            for (int j = 0; j < i; j++) {
                cp *= v[0][v[0].size() - j - 1];
            }
            ans = max(ans, cp);
        }
        cout << ans << '\n';
    }
}