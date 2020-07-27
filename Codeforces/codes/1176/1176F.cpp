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
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %
#define Dty pair< pal, int >

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vli ar[n][3];
    FOR(i, n){
        int x;
        cin>>x;
        FOR(j, x){
            int a, b;
            cin>>a>>b;
            ar[i][a-1].pb(b);
        }
        FOR(j, 3) {
            sort(ar[i][j].rbegin(), ar[i][j].rend());
            while(sz(ar[i][j]) > (j?1:3)) ar[i][j].pop_back();
        }
    }
    lli dp[n+1][11];
    FOR(i, n+1) FOR(j, 11) dp[i][j]=-1;dp[0][0] = 0;
    FOR(i, n){
        vector< Dty > dam[4];
        FOR(j, 10) dp[i+1][j] = dp[i][j];
        FOR(j, 3) FORR(x, ar[i][j]) { 
            vector< Dty > tem[4];
            FOR(k, 3) {
                if(dam[k+1].empty() || j+k+2>3) continue;
                FORR(el, dam[k+1]) tem[j+k+2].pb({{el.fi.fi+x, max(el.fi.se, x)}, el.se+1});
            }
            FOR(k, 3) FORR(x, tem[k+1]) dam[k+1].pb(x);
            dam[j+1].pb({{x, x}, 1});
        }
        FOR(j, 10) {
            if(dp[i][j]==-1) continue;
            FOR(k, 3) FORR(x, dam[k+1]) {
                int cur = j+x.se;
                dp[i+1][cur%10] = max(dp[i+1][cur%10], dp[i][j] + x.fi.fi + x.fi.se*(cur>=10));
            }
        }
    }
    cout<<*max_element(dp[n], dp[n]+10)<<endl;
}