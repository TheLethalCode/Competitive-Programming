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
        int n, w;
        cin >> n >> w;
        vector< int > cnt(32);
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            cnt[__builtin_ctz(x)]++;
        }
        int ans = 0, done = 0;
        while (done < n) {
            int curLen = 0, pos = 30;
            for (int i = 30; i >= 0;) {
                if (!cnt[i] || curLen + (1 << i) > w) {
                    i--;
                    continue;
                }
                curLen += 1 << i;
                done++;
                cnt[i]--;
            }
            ans++;
        }
        cout << ans << "\n";
    }
}