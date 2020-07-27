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
vpa v;

bool comp(int lh, int rh)
{
    return v[lh].fi-v[lh].se < v[rh].fi-v[rh].se;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    v.resize(n);
    FOR(i, n) cin>>v[i].fi;
    FOR(i, n) cin>>v[i].se;

    vi ch(n);
    FOR(i,n) ch[i] = i;
    sort(all(ch), comp);
    
    vi neg, pos, ze;
    FOR(i,n)
    { 
        int rt = v[ch[i]].fi - v[ch[i]].se;
        if (rt < 0) neg.pb(-rt); 
        else if(rt > 0) pos.pb(rt);
        else ze.pb(rt);
    }
    
    lli ans = 0, ns = neg.size(), ps = pos.size(), zs = ze.size();
    ans += ps*(ps-1)/2, ans += ps * zs;
    reverse(all(neg));
    
    for(auto te : pos)
    {
        int wt = lower_bound(all(neg), te) - neg.begin();
        ans += wt;
    }
    cout<<ans<<endl; 
}