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
    int n, m;
    cin>>n>>m;
    vli de(n+1, 0);
    FOR(i, m){
        int a, b, c;
        cin>>a>>b>>c;
        de[a]-=c, de[b]+=c;
    }
    vpal ne, po;
    FOR(i, n) 
        if(de[i+1]<0) ne.pb({-de[i+1], i+1});
        else if(de[i+1]>0) po.pb({de[i+1], i+1});
    vector< pair< pal , lli > > ans;
    int cnt = 0;
    for(auto el : ne){
        while(po[cnt].fi < el.fi){
            ans.pb({{el.se, po[cnt].se}, po[cnt].fi});
            el.fi-=po[cnt].fi, cnt++;
        }
        if(el.fi)
            ans.pb({{el.se, po[cnt].se}, el.fi}), po[cnt].fi-=el.fi;
        if(!po[cnt].fi) cnt++;
    }
    cout<<ans.size()<<endl;
    for(auto el : ans) cout<<el.fi.fi<<" "<<el.fi.se<<" "<<el.se<<endl;
}