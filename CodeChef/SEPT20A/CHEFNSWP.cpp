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

int findX(lli sum) {
    int lo = 1, hi = 1e9, mid, ans;
    while (lo <= hi) {
        mid = lo + hi >> 1;
        if (1LL * mid * (mid + 1) / 2 <= sum) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

lli solve(lli n) {
    lli sum;
    sum = n * (n + 1) / 2;
    if (sum & 1) {
        return 0;
    } else {
        sum >>= 1;
        lli x = findX(sum), dif = sum - x * (x+1) / 2, ans = 0, st, en;
        if (!dif) {
            ans += x * (x-1) / 2 + (n - x) * (n - x - 1) / 2;
            dif = sum - x * (x-1) / 2;
            if (dif < n) {
                st = max(1LL, x + 1 - dif), en = min(x - 1, n - dif);
                ans += en - st + 1;   
            }
        } else {
            st = max(1LL, x + 1 - dif), en = min(x, n - dif);
            ans += en - st + 1;   
            dif = sum - x * (x - 1) / 2;
            if (dif < n) {
                st = max(1LL, x - dif), en = min(x - 1, n - dif);
                ans += en - st + 1;   
            }
        }
        return ans;
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}