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
#define debugA(v,n) for(int i=0;i<n;i++) cout<<v[i]<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vector< vi > v(10000);
    FOR(i,n)
    {
        int a,m;
        cin>>a>>m;
        FOR(i,m)
        {
            int b;
            cin>>b;
            v[a].pb(b);
        }
    }
    set<int> ans;
    FOR(i,10000)
    {
        for(auto r:v[i])
        {
            if(!v[r].size())
                ans.insert(r);
        }
    }
    cout<<ans.size()<<endl;
}