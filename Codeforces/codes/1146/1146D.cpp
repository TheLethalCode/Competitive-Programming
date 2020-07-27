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
#define MAXC 1000000

int dp[MAXC+1], a, b, m, cur=0, mx=0;
lli ans=0;

int main(int argc, char **argv)
{
    crap;
    FOR(i, MAXC+1) dp[i]=mod;
    cin>>m>>a>>b;
    do{
        cur+=a, dp[cur]=mx=max(mx, cur);
        while(cur>=b) cur-=b, dp[cur]=mx;
    }while(cur);
    dp[0]=0;
    for(int i=0;i<mx;i++) if(dp[i]<=m) ans+=m-dp[i]+1;
    if(m >= mx){
        lli gc = __gcd(a, b), st = (mx+gc-1)/gc, en = m/gc;
        ans -= (st + en)*(en-st+1)*gc/2;
        ans += (en-st+1)*(m+1);
    }
    cout<<ans<<endl;
}