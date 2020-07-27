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
#define perc %
#define xors ^

lli powmod(lli n, lli p)
{
    if(!p) return 1;
    if(p perc 2) return powmod(n,p-1)*n perc mod;
    lli t = powmod(n,p/2);
    return t*t perc mod;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vector< vi > v(n);
    int fl=0;
    for(int i=0;i<n*n;i++)
    {
        if(!fl)
        {
            v[(i perc n)].pb(i+1);
            if((i perc n) == n-1)
                fl=1;
        }
        else
        {
            v[n - 1 - (i perc n)].pb(i+1);
            if((i perc n) == n-1)
                fl = 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int x : v[i])
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}