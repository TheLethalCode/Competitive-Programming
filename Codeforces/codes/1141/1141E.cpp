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

int n;
vli sum;
lli h;
vi v;

bool can(lli val)
{
    FOR(i,min((lli)n,val))
        if(-sum[i+1] >= h)
            return true;

    if(sum[n] >= 0)
        return false;

    if(h/(-sum[n]) < val/n)
        return true;
    
    // cout<<"hi";
    lli te = sum[n]*(val/n-1);
    // debug1(te);
    for(lli k = (val/n-1)*n+1; k<=val;k++)
    {
        // debug1(k);
        te+=v[(k%n?k%n-1:n-1)];
        if(-te>= h)
            return true;
    } 
    return false;
}

int main(int argc, char **argv)
{
    crap;
    cin>>h>>n;
    v.resize(n);
    FOR(i,n)
        cin>>v[i];
    sum.resize(n+1,0);
    FOR(i,n)
        sum[i+1]=sum[i]+v[i];
    // cout<<can(1);
    lli ans=1LL<<60;
    if(!can(ans))
        cout<<-1;
    else
    {
        for(int i=59;i>=0;i--)
        {
            // cout<<ans<<endl;
            if(can(ans-(1LL<<i)))
                ans-=1LL<<i;
        }
        cout<<ans;
    }
    nl;
}