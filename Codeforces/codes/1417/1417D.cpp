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
#define MAXC 10005
// %

int v[MAXC];

struct op {
    int i, j, x;
    op(int _i, int _j, int _x) : i(_i), j(_j), x(_x) {
        v[i] -= i * x;
        v[j] += i * x;
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        lli sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        if (sum % n) {
            cout << -1 << '\n';
            continue;
        }
        sum /= n;
        vector< op > ans;
        for (int i = 2; i <= n; i++) {
            int r = (i - v[i] % i) % i;
            if (r) {
                ans.pb(1, i, r);   
            }
            ans.pb(i, 1, v[i] / i);
        }
        for (int i = 2; i <= n; i++) {
            ans.pb(1, i, sum);
        }
        cout << ans.size() << '\n';
        for (auto it : ans) {
            cout << it.i << ' ' << it.j << ' ' << it.x << '\n';
        }
    } 
}