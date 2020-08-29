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
#define EPS 1e-8
// %
int n, d, v[MAXC];

bool can(double ans) {
    double prev = v[0];
    for (int i = 1; i < n; i++) {
        if (prev + ans > v[i] + d) {
            return false;
        }
        prev = max(prev + ans, 1.0 * v[i]);
    }
    return true;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v, v+n);
        double lo = 0, hi = 2*mod, ans = 1, mid;
        while (true) {
            mid = (lo + hi)/2;
            if (fabs(ans - mid)/mid < EPS) {
                break;
            }
            (can(mid) ? lo : hi) = mid;
            ans = mid;
        }
        cout << fixed << setprecision(8) << ans << '\n';
    }
}