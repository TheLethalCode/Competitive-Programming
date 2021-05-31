#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define C1 200005
#define C2 2005

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< lli > maxSum(n);
        lli totSum = 0;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            totSum += x;
            maxSum[i] = i? max(maxSum[i-1], totSum): totSum;
        }
        while (m--) {
            int x;
            cin >> x;
            lli ans = 0;
            if (x > maxSum.back()) {
                if (totSum < 1) {
                    cout << "-1 ";
                    continue;
                }
                lli cnt = (x - maxSum.back() + totSum - 1) / totSum;
                ans += cnt * n;
                x -= cnt * totSum;
            }
            ans += lower_bound(maxSum.begin(), maxSum.end(), x) - maxSum.begin();
            cout << ans << " ";
        }
        cout << "\n";
    }
}