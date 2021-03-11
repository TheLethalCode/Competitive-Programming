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
#define MAXC 4000005
#define MAX1 2005
// %

int n, m, x;
pair < int, int > a[MAX1], b[MAX1], dis[MAXC];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].fi >> b[i].se;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int xD = b[j].fi + 1 - a[i].fi, yD = b[j].se + 1 - a[i].se;
            if (xD > 0 && yD > 0) {
                dis[x++] = {xD, yD};
            }
        }
    }
    sort(dis, dis + x);
    
    int maTilNow = 0, ans = mod;
    for (int i = x - 1; i >= 0; i--) {
        ans = min(ans, dis[i].fi + maTilNow);
        maTilNow = max(maTilNow, dis[i].se);
    }
    ans = min(ans, maTilNow);
    cout << ans << '\n';
}