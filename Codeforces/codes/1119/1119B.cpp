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

int n,h;
int v[1010];
bool can(int val)
{
    if(val > n)
        return false;
    vi la;
    FOR(i,val)
        la.pb(v[i]);
    sort(la.rbegin(),la.rend());
    int ans=0;
    FOR(i,val)
        if(i%2)
            continue;
        else
            ans+=la[i];
    if(ans > h)
        return false;
    return true;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>h;
    FOR(i,n)
        cin>>v[i];
    int ans=1<<10;
    for(int i=9;i>=0;i--)
    {
        if(!can(ans-(1<<i)))
            ans-=1<<i;
    }
    cout<<ans-1;nl;
}