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
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

int main(int argc, char **argv)
{
    crap;
    int n, m, k;
    cin>>n>>m>>k;
    vi v(n), off(n+1, -1), pref(n+1);
    FOR(i, n) cin>>v[i];
    FOR(i, m) {
        int a, b;
        cin>>a>>b;
        off[a]=max(off[a], b);
    }
    sort(all(v));
    FOR(i, n) pref[i+1]=pref[i]+v[i];
    int dp[k+1];
    FOR(i, k+1) dp[i]=mod;
    dp[0]=0;
    FOR(i, k){
        FOR(j, i+1){
            if(off[i+1-j]==-1) continue;
            dp[i+1]=min(dp[i+1], dp[j]+pref[i+1]-pref[j+off[i+1-j]]);
        }
        dp[i+1]=min(dp[i+1], dp[i]+v[i]);
    }
    cout<<dp[k]<<endl;
}