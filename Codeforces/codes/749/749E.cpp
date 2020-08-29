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

struct BIT {
    int n;
    vector < lli > bit;
    BIT(int _n) : n(_n) {
        bit.assign(n+1, 0);
    }
    lli sum(lli r) {
        lli ans = 0;
        for (;r >= 0; r = (r & r + 1) - 1) {
            ans += bit[r];
        }
        return ans;
    }
    void inc(int x, lli val) {
        for (;x < n; x = x | x+1) {
            bit[x] += val;
        }
    }
    void reset(int _n) {
        n = _n;
        bit.assign(n, 0);
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    BIT A(n+1);
    long double cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        cnt -= (i+1)*A.sum(a[i]) - 1LL*i*(i+1)*(n-i)/4.0;
        A.inc(a[i], n - i);
    }
    cnt /= 1LL*n*(n+1)/2;
    A.reset(n+1);
    for (int i = n-1; i >= 0; i--) {
        cnt += A.sum(a[i]);
        A.inc(a[i], 1);
    }
    cout << fixed << setprecision(12) << cnt << '\n';
}