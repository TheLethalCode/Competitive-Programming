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
    int n,c;
    cin>>n>>c;
    vli a(n), b(n),pre_a(n+1,0),pre_b(n+1,0);
    FOR(i,n-1) { cin>>a[i]; pre_a[i+1] = pre_a[i] + a[i];}
    FOR(i,n-1) { cin>>b[i]; pre_b[i+1] = pre_b[i] + b[i];}
    vector< vli > dp(n,vli(2,1e18));
    dp[0][0] = dp[0][1] = 0;
    lli mi = 0;
    FOR(i,n)
    {
        if(!i)
            continue;
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + a[i-1];
        mi = min(mi,dp[i][0] - pre_b[i]);
        dp[i][1] = pre_b[i] + mi + c;
    }
    FOR(i,n)
        cout<<min(dp[i][0],dp[i][1])<<" ";
    cout<<endl;
}