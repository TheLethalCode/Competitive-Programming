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
#define MAXC 100005
#define EPS 1e-8
// %
int n, c1, X[MAXC], Y[MAXC];
double ans;

bool solve(double r){
    double l = -1e7, h = 1e7;
    FOR(i, n){
        double dis = fabs(r-Y[i]);
        if(r - dis < EPS){
            return false;
        }
        double ran = sqrt(r*r - dis*dis);
        l = max(l, X[i]-ran);
        h = min(h, X[i]+ran);
        if(l > h){
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n){
        cin >> X[i] >> Y[i];
        c1 += Y[i] > 0;
        Y[i] = abs(Y[i]);
    }
    if(c1 && c1!=n){
        cout << -1 << '\n';
        return 0;
    }
    double lo = 0.5, hi = 1e14, mid;
    while(true){
        mid = (lo+hi)/2;
        if(fabs(ans - mid)/max(1.0, ans) < EPS){
            break;
        }
        (solve(mid)?hi:lo) = ans = mid;
    }
    cout << fixed << setprecision(7) << ans << '\n';
}