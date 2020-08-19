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
    int n, k;
    cin >> n >> k;
    vector< pair< int, int > > v(n);
    FOR (i, n) {
        cin >> v[i].fi;
        v[i].se = i + 1;
    }
    sort(v.rbegin(), v.rend());
    sort(v.begin(), v.begin() + k, [&](auto l, auto r){
        return l.se < r.se;
    });
    int pr = 1, ans = 0;
    FOR (i, k) {
        ans += v[i].fi;
    }
    cout << ans << '\n';
    for (int i = 1; i < k; i++) {
        cout << v[i].se - pr << ' ';
        pr = v[i].se;
    }
    cout << n + 1 - pr << '\n';
}