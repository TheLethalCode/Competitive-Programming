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
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define MAXC 100005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int dp[MAXC] = {};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector < pair < int, int > > v(n);
    FOR(i, n){
        cin>>v[i].fi>>v[i].se;
    }
    for(int i=1;i<=m;i++){
        dp[i]=i;
        for(int j=0;j<n;j++){
            int mi = v[j].fi - v[j].se;
            int ma = v[j].fi + v[j].se;
            if(i > ma){
                dp[i] = min(dp[i], dp[max(1, 2*v[j].fi-i)-1] + (i-ma));
            }
            else if(i >= mi){
                dp[i] = min(dp[i], dp[i-1]);
            }
        }
    }
    cout << dp[m] << "\n";
}