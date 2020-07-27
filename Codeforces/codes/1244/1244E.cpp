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

int n;
lli v[200005], k, pref[200005], suff[200005];

bool can(lli ans){
    if(ans >= v[n-1]-v[0]) return true;
    for(int i=0;i<n;i++){
        int pos = lower_bound(v, v+n, v[i]+ans) - v;
        if(pos==n) break;
        lli tem = (i+1)*v[i] - pref[i] +  suff[pos] - (v[i]+ans)*(n-pos);
        if(tem <= k) return true;
    }
    for(int i=n-1;i>=0;i--){
        int pos = lower_bound(v, v+n, v[i]-ans) - v;
        if(v[pos] != v[i]-ans) pos--;
        if(pos<0) break;
        lli tem = suff[i]-(n-i)*v[i] + (pos+1)*(v[i]-ans)-pref[pos];
        if(tem <= k) return true;
    }
    return false;
}
// %
int main(int argc, char **argv)
{
    crap;
    cin>>n>>k;
    FOR(i, n) cin>>v[i];
    sort(v, v+n);
    pref[0]=v[0]; FOR(i, n-1) pref[i+1]=pref[i]+v[i+1];
    suff[n-1]=v[n-1]; for(int i=n-2;i>=0;i--) suff[i]=suff[i+1]+v[i];

    lli ans = 1LL<<32;
    for(int i=31;i>=0;i--){
        if(can(ans-(1LL<<i)))
            ans-=1LL<<i;
    }
    if(can(0)) ans=0;
    cout<<ans<<endl;
}