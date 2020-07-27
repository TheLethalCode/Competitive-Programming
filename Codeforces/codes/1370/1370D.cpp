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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int n, k, ar[200005];
// %

bool can(int val){
    vi v(n);
    vector< vi > dp(n, vi(2, 0));
    FOR(i, n) v[i] = (ar[i]>val);
    if(!v[0]) dp[1][0]=2;
    else dp[1][0]=!v[1];
    dp[1][1]=1 + !v[1];
    for(int i=2;i<n;i++){
        if(!v[i]){
            dp[i][0] = dp[i-1][0]+1;
            dp[i][1] = dp[i-1][1]+1;
        }
        else{
            if(dp[i-1][0] & 1) dp[i][0] = dp[i-1][0]+1;
            else dp[i][0] = dp[i-1][0];
            if(dp[i-1][1] & 1) dp[i][1] = dp[i-1][1];
            else dp[i][1] = dp[i-1][1]+1;
        }
    }
    return max(dp[n-1][0], dp[n-1][1]) >= k;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>k;
    vi ord(n);
    FOR(i, n) cin>>ar[i];
    int ans = 1<<30;
    for(int i=29;i>=0;i--)
        if(can(ans-(1<<i)))
            ans-=1<<i;
    cout<<ans<<endl;
}