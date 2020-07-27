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
int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vpa v(n);
    FOR(i, n) cin>>v[i].fi>>v[i].se;
    map< pa, set<pa> > slope;
    FOR(i, n){
        for(int j=i+1;j<n;j++){
            int md = abs(v[i].fi-v[j].fi), mn = abs(v[i].se-v[j].se);
            int mgc = __gcd(mn, md);
            mn/=mgc, md/=mgc;
            if((v[i].fi - v[j].fi)*(v[i].se-v[j].se) < 0) mn=-mn;
            int cn = md*v[i].se - mn*v[i].fi, cd = md;
            int cgc = __gcd(abs(cn), abs(cd));
            if(cgc) cn/=cgc, cd/=cgc;
            if(!cd) cn = v[i].fi;
            slope[{mn, md}].insert({cn, cd});
        }
    }
    lli ig = 0, ed = 0;
    for(auto el : slope){
        lli m = el.se.size();
        ig+=m*(m-1)/2, ed+=m;
    }
    cout<<ed*(ed-1)/2 - ig<<endl;
}