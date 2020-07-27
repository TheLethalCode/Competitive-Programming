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
vi pos;
int n, k;
vli dp;

lli solve(int cur){
    if(cur <= 0) return 0;
    if(dp[cur]!=-1) return dp[cur];
    auto tem = lower_bound(all(pos), cur-k);
    if(tem != pos.end() && *tem <= cur) return dp[cur] = *tem + solve(*tem-k-1);
    if(tem != pos.end() && *tem <= cur+k) 
        return dp[cur] = min(*tem + solve(*tem-k-1), cur + solve(cur-1));
    return dp[cur] = cur+solve(cur-1);
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>k;
    string s;
    cin>>s;
    dp.assign(n+1, -1);
    FOR(i, sz(s)) if(s[i]=='1') pos.pb(i+1);
    cout<<solve(n)<<endl;
}