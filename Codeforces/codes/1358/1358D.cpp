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
    lli n, x;
    cin>>n>>x;
    vli v(n);
    FOR(i, n) cin>>v[i];
    vli hu(n+1, 0), d(n+1, 0);
    FOR(i, n) {
        hu[i+1]=hu[i] + v[i]*(v[i]+1)/2;
        d[i+1]=d[i]+v[i];
    }

    int pos = lower_bound(all(d), x) - d.begin();
    if(d[pos] != x)
        pos--;
    lli mo = pos, da = x - d[pos];
    lli ans = hu[mo] + da*(da+1)/2;
    lli st = 0;
    for(int j=mo+1;j<=n;j++){
        st += v[j-1] - da;
        int pos = lower_bound(all(d), st) - d.begin();
        if(d[pos] != st) pos--;
        lli le = st - d[pos];
        lli temp = hu[j] - hu[pos] - le*(le+1)/2;
        ans = max(ans, temp);
        da = 0;
    }
    for(int j=1;j<=mo;j++){
        st+=v[j-1] - da;
        int pos = lower_bound(all(d), st) - d.begin();
        if(d[pos] != st) pos--;
        lli le = st - d[pos];
        lli temp = hu[n] + hu[j] - hu[pos] - le*(le+1)/2;
        ans = max(ans, temp);
        da = 0;
    }
    cout<<ans<<endl;
}