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
#define sz(a) (int)(a.size())
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        lli n, x;
        cin >> n >> x;
        vector< lli > v(n);
        FOR(i, n){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int dp[n+1] = {}, ans = 0;
        for(int i=n-1;i>=0;i--){
            lli cnt = (x+v[i]-1)/v[i];
            if(i + cnt <= n ){
                dp[i] = 1 + dp[i+cnt];
                ans = max(ans, dp[i]);
            }
        }
        cout << ans << "\n";
    }
}