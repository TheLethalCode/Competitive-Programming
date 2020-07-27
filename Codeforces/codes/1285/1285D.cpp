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

int dfs(vi &v, int i)
{
    if(i < 0)
        return 0;

    int te = 1<<i;

    vi ze, one;
    for(int a : v)
        if(a & te)
            one.pb(a);
        else
            ze.pb(a);
    
    if(one.empty())
        return dfs(ze, i-1);
    if(ze.empty())
        return dfs(one, i-1);

    int x = dfs(one, i-1), y = dfs(ze, i-1);
    return ((1<<i) + min(x,y));
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;

    vi v(n);
    FOR(i,n) cin>>v[i];
    cout<<dfs(v, 29)<<endl;
}