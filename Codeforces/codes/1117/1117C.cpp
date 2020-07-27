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
lli x1, y11, x2, y2;
string s;
vpal m;

bool can(lli ans)
{
    int rem = ans % n;
    lli times = ans/n;
    pal pos = {times * m[n].fi, times * m[n].se};
    pos.fi += m[rem].fi, pos.se += m[rem].se; 
    pos.fi += x1, pos.se += y11;
    if(abs(pos.fi - x2) + abs(pos.se - y2) > ans)
        return false;
    return true;
}

int main(int argc, char **argv)
{
    crap;
    cin>>x1>>y11>>x2>>y2>>n>>s;
    lli ans = 1LL<<52;
    m.resize(n+1);

    m[0] = {0, 0};
    for(int i=0;i<n;i++)
    {
        m[i+1] = m[i];
        if(s[i] == 'U')
            m[i+1].se ++;
        if(s[i] == 'D')
            m[i+1].se --;
        if(s[i] == 'L')
            m[i+1].fi --;
        if(s[i] == 'R')
            m[i+1].fi ++;
    }

    for(int i=51;i>=0;i--)
        if(can(ans - (1LL<<i)))
            ans -= 1LL<<i;

    if(ans == 1LL<<52)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
}