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

// %
int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    set< pa > ans;
    ans.insert({0, 0});
    ans.insert({0, 1});
    ans.insert({1, 0});
    ans.insert({1, 1});
    for(int i=1;i<=n;i++) FOR(x, 2) FOR(y, 2) ans.insert({i+x, i+y});
    cout<<sz(ans)<<endl;
    for(auto el : ans) cout<<el.fi<<" "<<el.se<<endl;
}