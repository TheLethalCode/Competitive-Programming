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

int solve(vector< lli > &v, int l, int r) {
    if (l > r) {
        return 0;
    }
    vector< lli > lis;
    for (int i = l; i <= r; i++) {
        if (v[i] - i < v[l-1] - (l-1) || v[i] - i > v[r+1] - (r+1)) {
            continue;
        }
        auto it = upper_bound(lis.begin(), lis.end(), v[i] - i);
        if (it == lis.end()) {
            lis.pb(v[i] - i);
        } else {
            *it = v[i] - i;
        }
    }
    return r - l + 1 - (int)lis.size();
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector< lli > v(n+2);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    v[n+1] = 2*mod;
    v[0] = -mod;
    vector< int > b = {0};
    for (int i = 0, x; i < k; i++) {
        cin >> x;
        b.pb(x);
    }
    b.pb(n+1);
    int ans = 0;
    for (int i = 1; i <= k+1; i++) {
        if (v[b[i]] - v[b[i-1]] < b[i] - b[i-1]) {
            ans = -1;
            break;
        }
        ans += solve(v, b[i-1]+1, b[i]-1);
    }
    cout << ans << '\n';
}