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
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        a -= c, b -= c;
        if (a + b + c > n || (n != 1 && !a && !b && c==1)) {
            cout << "Case #" << z << ": IMPOSSIBLE\n";
            continue;    
        }
        vector < int > ans(n, 1);
        for (int i = 0, st = 2 - (a==n-1); i < a; i++) {
            ans[i] = st++;
        }
        for (int i = n - 1, st = 2 - (b==n-1); i > n - 1 - b; i--) {
            ans[i] = st++;
        }
        int l = a, r = n - 1 - b;
        if (c == 1) {
            ans[!a?l:r] = n;
        } else {
            for (int i = l; i < l + c - 1; i++) {
                ans[i] = n;
            }
            ans[r] = n;
        }
        cout << "Case #" << z << ": ";
        FOR (i, n) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}