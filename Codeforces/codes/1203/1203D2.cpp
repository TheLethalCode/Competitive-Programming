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
    
    string t,s;
    cin>>s>>t;
    
    int n=t.size(), m=s.size();
    vector< vi > al(26);

    for(int i=0;i<m;i++)
        al[s[i]-'a'].pb(i);

    int st = -1;
    vpa v(n);
    for(int i=0;i<n;i++)
        v[i].fi = *upper_bound(all(al[t[i]-'a']), st), st = v[i].fi;

    st = m;
    for(int i=n-1;i>=0;i--)
        v[i].se = *upper_bound(al[t[i]-'a'].rbegin(), al[t[i]-'a'].rend(), st, greater<int>()), st = v[i].se;

    int ans = 0;
    for(int i=0;i<n-1;i++)
        ans = max(v[i+1].se - v[i].fi-1, ans);

    // for(int i=0;i<n;i++)
    //     cout<<v[i].fi <<" "<<v[i].se<<endl;
    ans = max3(ans, v[0].se, m - 1 - v[n-1].fi);
    cout<<ans<<endl;
}