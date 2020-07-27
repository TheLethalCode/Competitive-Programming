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

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int m, n, k, t;
bool can(int ans, vi &v, vector< pair< pa, int > > &tr)
{
    if(ans > m)
        return false;
    
    int d = v[m-ans];
    vpa ar;
    FOR(i, k) 
        if(tr[i].se > d) 
            ar.pb(tr[i].fi);
    if(ar.empty())
        return true;
    int squ = 0, ti = n+1;
    int i = 0, z = ar.size();
    while(i<z){
        squ = ar[i].fi-1;
        int de = ar[i].se;
        int j=i+1;
        while(j<z && ar[j].fi <= de){
            de=max(ar[j].se, de), j++;
        }
        i=j;
        ti += (de-squ)*2;
    }
    return ti <= t;
}

int main(int argc, char **argv)
{
    crap;
    cin>>m>>n>>k>>t;
    vi v(m);
    vector< pair< pa, int > > tr(k);
    FOR(i, m) cin>>v[i];
    FOR(i, k) cin>>tr[i].fi.fi>>tr[i].fi.se>>tr[i].se;
    sort(all(v)), sort(all(tr));
    int ans = 0;
    for(int i=24;i>=0;i--){
        if(can(ans+(1<<i), v, tr))
            ans+=1<<i;
    }
    cout<<ans<<endl;
}