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

int n;
string s;
int x,y;
vpa pos;

map<char, pa> mp;

bool can(int v)
{
    int fix = pos[n].fi, fiy = pos[n].se;
    if(v >= n)
        return true;
    for(int i=0;i<n-v+1;i++)
    {
        int remx = fix - (pos[i+v].fi - pos[i].fi);
        int remy = fiy - (pos[i+v].se - pos[i].se); 
        if(abs(x-remx) + abs(y-remy) > v)
            continue;
        if((v - abs(x-remx) + abs(y-remy)) & 1)
            continue;
        return true; 
    }
    return false;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    cin>>s;
    cin>>x>>y;
    pos.resize(n+1,{0,0});
    mp['U'] = {0,1}, mp['R'] = {1,0}, mp['D'] = {0,-1}, mp['L'] = {-1,0};
    for(int i=0;i<n;i++)
    {
        pos[i+1] = pos[i];
        pos[i+1].fi += mp[s[i]].fi, pos[i+1].se += mp[s[i]].se;
    }

    if(abs(x) + abs(y) > n || (n - abs(x) + abs(y))&1 )
    {
        cout<<-1<<endl;
        return 0;
    }

    if(pos[n].fi == x & pos[n].se == y)
    {
        cout<<0<<endl;
        return 0;
    }

    int ans = 1<<25;
    for(int i=24;i>=0;i--)
        if(can(ans-(1<<i)))
            ans-=1<<i;
    cout<<ans<<endl;
}