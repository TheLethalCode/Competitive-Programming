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
#define MAXC 5005
#define MAXP 505
// %

int n, m, a, b, k, t, q, ok, cnt, dp[MAXC][MAXP], H[11];
lli r, x, y, z, ans;
string s, c;

int solve(int c, int p){
    if(dp[c][p]!=-1){
        return dp[c][p];
    }
    if(!c || !p){
        return dp[c][p] = 0;
    }
    int ans = 0;
    for(int i=0;i<=min(c, k);i++){
        ans = max(ans, solve(c-i, p-1) + H[i]);
    }
    return dp[c][p] = ans;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    map<int, int > cards, fav;
    FOR(i, n*k){
        cin >> a;
        cards[a]++;
    }
    FOR(i, n){
        cin >> a;
        fav[a]++;
    }
    FOR(i, k){
        cin >> H[i+1];
    }
    memset(dp, 0xff, sizeof(dp));
    FORR(f, fav){
        ans += solve(cards[f.fi], f.se);
    }
    cout << ans << '\n';
}