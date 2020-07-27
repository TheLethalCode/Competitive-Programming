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

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %
#define xors ^

int main(int argc, char **argv)
{
    crap;
    int n,m;
    cin>>n>>m;

    if(n < m)
        swap(n,m);
    
    lli dp[n+1][2][2];
    
    dp[0][0][1] = dp[0][1][1] = 0;
    dp[0][0][0] = dp[0][1][0] = 1;

    FOR(i,n)
    {
        dp[i+1][0][0] = dp[i][0][1] perc mod;
        dp[i+1][0][1] = (dp[i][1][0] + dp[i][1][1]) perc mod;
        dp[i+1][1][0] = dp[i][1][1] perc mod;
        dp[i+1][1][1] = (dp[i][0][0] + dp[i][0][1]) perc mod;    
    }

    lli ans = 0;
    FOR(i,2) FOR(j,2) ans += dp[n][i][j], ans = ans perc mod;

    vli fib(m+1,0);

    fib[1] = fib[2] = 2;  
    for(int i=3;i<=m;i++)
        fib[i] = fib[i-1] + fib[i-2], fib[i] = fib[i] perc mod;

    FOR(i,m)
        ans += fib[i], ans = ans perc mod;

    cout<<ans<<endl;
}