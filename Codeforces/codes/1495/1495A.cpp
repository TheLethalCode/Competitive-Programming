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
        vector< lli > a, b;
        for (int i = 0, x, y; i < 2*n; i++) {
            cin >> x >> y;
            if (x) {
                a.pb(abs(x));
            } else {
                b.pb(abs(y));
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += sqrt(a[i]*a[i] + b[i]*b[i]);
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
}