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

#define perc %

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    vpal dp(2*1e6+1, {0, 0});
    dp[3] = {1, 1};
    for(int i=4;i<=2*1e6;i++){
        dp[i].fi = 2*dp[i-2].fi + dp[i-1].fi;
        if(!dp[i-2].se && !dp[i-1].se) dp[i].se = 1, dp[i].fi++;
        dp[i].fi = dp[i].fi perc mod;
    }
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n].fi*4) perc mod<<endl;
    }
}