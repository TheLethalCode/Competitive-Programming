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
#define MAXC 205
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

vector< int > ed[MAXC];
int dp[MAXC][MAXC], W[MAXC], n, k;

int solve(int u, int dep, int p=-1){
    if(dp[u][dep]!=-1){
        return dp[u][dep];
    }
    if(dep >= n){
        return dp[u][dep] = 0;
    }
    if(!dep){
        dp[u][dep] = W[u];
        FORR(v, ed[u]){
            if(v!=p){
                dp[u][dep] += solve(v, k, u);
            }
        }
    }
    else{
        int sum = 0;
        dp[u][dep] = 0;
        FORR(v, ed[u]){
            if(v!=p){
                sum += solve(v, max(k-dep, dep-1) , u);
            }
        }
        FORR(v, ed[u]){
            if(v!=p){
                dp[u][dep] = max(dp[u][dep], sum - solve(v, max(k-dep, dep-1), u) + solve(v, dep-1, u));
            }
        }
    }
    return dp[u][dep] = max(dp[u][dep], solve(u, dep+1, p));
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    memset(dp, 0xff, sizeof dp);
    FOR(i, n){
        cin >> W[i+1];
    }
    FOR(i, n-1){
        int a, b;
        cin >> a >> b;
        ed[a].pb(b);
        ed[b].pb(a);
    }
    cout<< solve(1, 0) << "\n";
}