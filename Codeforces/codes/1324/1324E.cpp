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
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    vi v(n);
    vi pref(n+1,0);
    FOR(i, n) cin>>v[i], v[i]--, pref[i+1] = (pref[i]+v[i])%h;
    vector< vi > num(n+1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            if((pref[i]+j)%h <= r && (pref[i]+j)%h >= l)
                num[i].pb(j);
    
    vector< vi > dp(n+1, vi(n+1,0));
    for(int k:num[1])
        dp[1][k] = 1;
    for(int i=2;i<=n;i++)
    {
        dp[i][0] = dp[i-1][0];
        if(pref[i] >= l & pref[i] <= r)
            dp[i][0]++;
        for(int j=1;j<=i;j++)
        {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
            if(num[i].empty())
                continue;
            int pos = lower_bound(all(num[i]), j) - num[i].begin();
            if(pos < num[i].size() & num[i][pos] == j)
                dp[i][j]++;
        }
    }
    cout<<*max_element(all(dp[n]))<<endl;
}