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

vli pref;
int n, v[1000002];
lli dp[1000002][2];

// %
lli solve(lli k){
    dp[0][0] = dp[0][1] = 0;
    for(int i=1;i<n;i++){
        dp[i][0] = dp[i-1][0] + pref[i-1]%k;
        if(v[i] >=  k - (pref[i-1]%k)) dp[i][0] = min(dp[i][0], dp[i-1][1] + k - (pref[i-1]%k));
        dp[i][1] = min(dp[i-1][0] + pref[i-1]%k, dp[i-1][1] + k - (pref[i-1]%k));
    }
    return min(dp[n-1][0], dp[n-1][1]);
}

int main(int argc, char **argv)
{
    crap;
    lli ans = 1e18, sum=0;
    vli fact;

    cin>>n;
    pref.assign(n, 0);
    FOR(i, n) cin>>v[i], sum+=v[i], pref[i]=sum;
    if(sum==1){
        cout<<-1<<endl;
        return 0;
    }
    
    for(lli i=2; i*i <= sum; i++){
        if(sum%i) continue;
        fact.pb(i);
        while(!(sum%i)) sum/=i;
    }
    if(sum!=1) fact.pb(sum);
    FORR(x, fact) ans = min(ans, solve(x));
    cout<<ans<<endl;
}