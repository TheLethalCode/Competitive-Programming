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

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;

    vi v(n+1);
    for(int i = 1; i<=n ; i++)
        cin>>v[i];

    vector< vi > fact(1e6+1), rfact(1e6+1);
    for(int i=1;i<=1e6;i++)
        for(int j=i;j<=1e6;j+=i)
            fact[j].pb(i);

    vli dp(n+1,0), dp2(n+1,0);

    dp[0] = dp2[0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int a : fact[v[i]])
            if(a > i)
                break;
            else
                dp[a] += dp2[a-1], dp[a] %= mod;
        
        for(int a : fact[v[i]])
            if(a > i)
                break;
            else
                dp2[a] = dp[a];

    }

    lli ans = 0;
    for(int i=1;i<=n;i++)
        ans+=dp[i], ans %= mod;
        
    cout<<ans<<endl;
}