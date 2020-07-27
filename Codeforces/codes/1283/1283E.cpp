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
    vi v(n);
    FOR(i,n) cin>>v[i];
    sort(all(v));
    
    vpa dp1(n+1,{0,-1}), dp2(n+1,{0,-1});

    for(int i=0;i<n;i++)
    {
        if(abs(dp1[i].se - v[i]) <= 1)
            dp1[i+1] = dp1[i];
        else
            dp1[i+1].fi = dp1[i].fi + 1, dp1[i+1].se = v[i]+1;
    }

    for(int i=0;i<n;i++)
    {
        if(abs(dp2[i].se - v[i]) > 1)
            dp2[i+1].fi = dp2[i].fi + 1, dp2[i+1].se = v[i] - 1;
        else if(dp2[i].se <= v[i])
            dp2[i+1].fi = dp2[i].fi + 1, dp2[i+1].se = dp2[i].se+1;
        else
            dp2[i+1] = dp2[i];
    }
    cout<<dp1[n].fi<<" "<<dp2[n].fi<<endl;
}