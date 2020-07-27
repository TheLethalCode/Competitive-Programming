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

int n, m;
lli v[101][101], dp[101][101];

lli solve(int ux, int uy, int desx, int desy, lli val){
    for(int i=ux;i<=desx;i++){
        for(int j=uy;j<=desy;j++){
            dp[i][j] = -1;
        }
    }
    for(int i=ux;i<=desx;i++){
        for(int j=uy;j<=desy;j++){
            if(v[i][j] < val+(i-ux)+(j-uy)) continue;
            dp[i][j] = v[i][j] - (val + (i-ux) + (j-uy));
            if(i==ux && j==uy) continue;
            if((i==ux || dp[i-1][j]==-1) && (j==uy || dp[i][j-1]==-1)) {
                dp[i][j] = -1;
                continue;
            }
            if(i==ux || dp[i-1][j]==-1) {
                dp[i][j] += dp[i][j-1];
            }
            else if(j==uy || dp[i][j-1]==-1){
                dp[i][j] += dp[i-1][j];
            }
            else{
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[desx][desy];
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        lli ans = 1LL*mod*mod;
        cin>>n>>m;
        FOR(i, n) {
            FOR(j, m){
                cin>>v[i][j];
            }
        }
        FOR(i, n) {
            FOR(j, m){
                lli a = solve(0, 0, i, j, v[i][j]-i-j);
                lli b = solve(i, j, n-1, m-1, v[i][j]);
                if(a!=-1 && b!=-1) ans = min(ans, a+b);
            }
        }
        cout<<ans<<endl;
    }
}