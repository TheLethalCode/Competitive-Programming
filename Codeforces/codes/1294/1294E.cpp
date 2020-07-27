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
int n, m;
int solve(vi &v, int col)
{
    vi temp = v;
    vi cnt(n+1,0);
    FOR(i,n)
        if(temp[i]%m == col && temp[i] <= n*m)
            temp[i]=(temp[i]/m)-i-(col==0), cnt[(n-temp[i])%n]++;
    int ans = 1e9;
    FOR(i, n+1)
        ans = min(ans, n-cnt[i]+i);
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    vector< vi > v(m, vi(n,0));
    FOR(i,n) FOR(j,m) cin>>v[j][i];
    int ans = 0;
    FOR(i, m) ans+=solve(v[i], (i+1)%m);
    cout<<ans<<endl;
}