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

bool comp(pa l,pa r)
{
    if(l.se == r.se)
        return l.fi > r.fi;
    return l.se > r.se;
}

int main(int argc, char **argv)
{
    crap;
    int n,k;
    cin>>n>>k;
    vpa v(n);
    FOR(i,n)
        cin>>v[i].fi>>v[i].se;
    sort(all(v),comp);
    vli dp(n+1);
    multiset<lli> wtf;
    FOR(i,k)
    {
        dp[i+1]=dp[i]+v[i].fi;
        wtf.insert(v[i].fi);
    }
    for(int i=k;i<n;i++)
    {
        wtf.insert(v[i].fi);
        dp[i+1]=dp[i]+v[i].fi;
        dp[i+1]-=*wtf.begin();
        wtf.erase(wtf.begin());
    }
    lli ans=0;
    FOR(i,n)
        ans=max(ans,dp[i+1]*v[i].se);
    
    cout<<ans;nl;
}