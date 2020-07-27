#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb push_back
#define pp pop_back

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    int n, x;
    cin>>n>>x;
    lli v[n], pref[n+1];
    pref[0]=0;
    FOR(i, n) cin>>v[i], pref[i+1] = pref[i]+v[i];

    lli ans = 0, ma = 0, dp[n+2][2];
    dp[n+1][1] = dp[0][0] = 0;
    FOR(i, n){
        dp[i+1][0] = max3(dp[i][0]+v[i], v[i], 0LL);
        dp[n-i][1] = max3(dp[n-i+1][1]+v[n-i-1], v[n-i-1], 0LL);
        ans = max(ans, dp[i+1][0]);
    }    
    FOR(i, n){
        ma = max(ma, dp[i][0]-x*pref[i]);
        ans = max(ans, dp[i+2][1]+x*pref[i+1]+ma);
    }
    cout<<ans<<endl;
}