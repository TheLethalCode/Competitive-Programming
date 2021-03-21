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
    while (t--) {
        int n;
        cin >> n;
        vector< lli > c(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        set < lli > odd, even;
        lli ans = 1e18, oddSum = 0, evenSum = 0;
        lli oddAns = 0, evenAns = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2) {
                oddSum += c[i];
                odd.insert(c[i]);
                lli low = *odd.begin(), cnt = (i + 1) / 2;
                oddAns = (oddSum - low) + (n - cnt + 1) * low; 
            } else {
                evenSum += c[i];
                even.insert(c[i]);
                lli low = *even.begin(), cnt = (i + 1) / 2;
                evenAns = (evenSum - low) + (n - cnt + 1) * low; 
            }
            if (i > 1) {
                ans = min(ans, oddAns + evenAns);
            }
        }
        cout << ans << "\n";
    }
}