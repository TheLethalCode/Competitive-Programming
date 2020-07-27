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

int n,m;

bool isval(int i, int j)
{
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    vector< vi > v(n,vi(m,0)),dp(n+1,vi(m,1e9));
    FOR(i,n)
        FOR(j,m)
            cin>>v[i][j];
    
    FOR(i,m)
        dp[0][i]=0;

    FOR(i,n)
        FOR(j,m)
        {
            FOR(k,3)
                if(isval(i,j-1+k))
                    dp[i+1][j] = min(dp[i+1][j],dp[i][j-1+k]);
            dp[i+1][j]+=v[i][j];
        }
    cout<<*min_element(all(dp[n]));nl;
}