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
    string l,r;
    cin>>l>>r;
    vector< vi > lh(200),rh(200);
    FOR(i,n)
        lh[l[i]].pb(i),rh[r[i]].pb(i);
    vpa ans;
    for(int i='a';i<='z';i++)
    {
        while(lh[i].size() && rh[i].size())
        {
            ans.pb({lh[i].back(),rh[i].back()});
            lh[i].pop_back(),rh[i].pop_back();
        }
    }
    int i='a';
    while(lh['?'].size() && i<='z')
    {
        while(rh[i].size() && lh['?'].size())
            ans.pb({lh['?'].back(),rh[i].back()}), lh['?'].pop_back(),rh[i].pop_back();
        i++;
    }
    i='a';
    while(rh['?'].size() && i<='z')
    {
        while(lh[i].size() && rh['?'].size())
        {
            // debug2(rh['?'].back(),lh[i].back());
            ans.pb({lh[i].back(),rh['?'].back()}), rh['?'].pop_back(),lh[i].pop_back();
        }   
        i++;
    }
    while(lh['?'].size() && rh['?'].size())
    {
        ans.pb({lh['?'].back(),rh['?'].back()});
        lh['?'].pop_back(),rh['?'].pop_back();
    }
    cout<<ans.size();nl;
    for(auto k:ans)
        cout<<k.fi+1<<" "<<k.se+1<<"\n";
}