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
#define mp make_pair

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
    int n;
    cin>>n;
    vpa v(n), tem;;
    FOR(i, n) cin>>v[i].fi, v[i].se=i;
    sort(all(v));
    
    int dp[n][2];
    FOR(i, n) dp[i][0] = dp[i][1] = 0;
    for(int i=3;i<=n-3;i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        dp[i][1] = dp[i-2][0]+v[i].fi-v[i-1].fi;
    }
    cout<<v[n-1].fi - v[0].fi - max(dp[n-3][0], dp[n-3][1])<<" ";
    
    int team = 1;
    vi ans(n);
    for(int i=n-3;i>=3;i--){
        if(dp[i][0] > dp[i][1]) ans[v[i-1].se]=team;
        else 
            ans[v[i-1].se] = ans[v[i-2].se] = ans[v[i-3].se] = ++team, i-=2;
    }
    ans[v[n-1].se]=ans[v[n-2].se]=ans[v[n-3].se]=1;
    ans[v[0].se]=ans[v[1].se]=ans[v[2].se]=team;
    cout<<team<<endl;
    debugA(ans);
}