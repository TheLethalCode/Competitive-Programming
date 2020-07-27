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

void dfs(int u, vector< vpal > &ed, vli &v, vector< set<lli> > &dp, vector< bool > &ch)
{
    ch[u] = true;
    for(pa k : ed[u])
    {
        if(ch[k.fi])
            continue;
        dfs(k.fi,ed,v,dp,ch);
        dp[u].insert(*(dp[k.fi].rbegin()) + v[u] - k.se);
        if( dp[u].size() > 2)
            dp[u].erase(dp[u].begin());
    }
    
    dp[u].insert(v[u]);
    if(dp[u].size() > 2)
        dp[u].erase(dp[u].begin());
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vli v(n+1);
    FOR(i,n) cin>>v[i+1];

    vector< vpal > ed(n+1);
    FOR(i,n-1)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ed[a].pb({b,c});
        ed[b].pb({a,c});
    }

    vector< set<lli> > dp(n+1);
    vector< bool > ch(n+1, false);
    dfs(1,ed, v, dp, ch);

    lli st = 0;
    vli dp1(n+1,0);
    FOR(i,n)
    {
        // cout<<i+1<<": ";
        for(lli k : dp[i+1])
            st=max(st, k), dp1[i+1] += k;
        // cout<<endl;
        st = max(st, dp1[i+1] - ((dp[i+1].size() == 2)?v[i+1]:0));
    }
    cout<<st<<endl;
}