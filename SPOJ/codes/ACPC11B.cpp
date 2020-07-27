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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vpa v;
        FOR(i,n)
        {
            int a;
            cin>>a;
            v.pb({a,0});
        }
        cin>>n;
        FOR(i,n)
        {
            int a;
            cin>>a;
            v.pb({a,1});
        }
        sort(all(v));
        int ans = 1e9;
        FOR(i,v.size()-1)
            if(v[i].se != v[i+1].se)
                ans=min(ans,abs(v[i].fi-v[i+1].fi));
        cout<<ans<<endl;
    }
}