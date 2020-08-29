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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

struct BIT {
    int n;
    vector < lli > bit;
    BIT (int _n) : n(_n) {
        bit.assign(n, 0);
    }
    BIT (vector< lli > &v) : BIT(v.size()) {
        for (int i = 0; i < n; i++) {
            inc(i, v[i]);
        }
    }
    void reset(int _n) {
        n = _n;
        bit.assign(n, 0);
    }
    lli sum(int r) {
        lli ret = 0;
        for (;r >= 0; r = (r & (r+1)) - 1) {
            ret += bit[r];
        }
        return ret;
    }
    lli sum(int l, int r) {
        return sum(r) - sum(l-1);
    }
    void inc(int i, lli del) {
        for (;i < n; i = i | (i+1)) {
            bit[i] += del;
        }
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <lli> dp(n, 1);
    BIT ans(n+2);
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            ans.inc(a[i]+1, dp[i]);
            dp[i] = ans.sum(a[i]);
        }
        ans.reset(n+2);
    }
    lli ret = 0;
    for (int i = 0; i < n; i++) {
        ret += dp[i];
    }
    cout << ret << '\n';
}