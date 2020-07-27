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
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %

int main(int argc, char **argv)
{
    crap;
    lli u, v;
    cin>>u>>v;
    if(u > v)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(u == v && u == 0)
    {
        cout<<0<<endl;
        return 0;
    }
    vi nu(60);
    lli te = u;
    int pos = 0;
    while(te)
        nu[59-pos] = te & 1, te /= 2, pos++;
    int prev = 0;
    for(int i = 59; i >= 0;i--)
    {
        if( ( (nu[i]+(prev>>1)) &1) == (  ( ( 1LL << (59-i) ) & v ) >> (59-i) ) )
        {
            prev = nu[i] + (prev>>1); 
            continue;
        }
        if(i==59)
        {
            cout<<-1<<endl;
            return 0;
        }
        nu[i+1] += 2;
        prev = nu[i] + (prev>>1) + 1;
    }
    int n = *max_element(all(nu));
    vli ans(n,0);
    for(int i=0;i<60;i++)
    {
        for(int j=0;j<nu[i];j++)
        {
            ans[j] += (1LL<<(59-i));
        }
    }
    cout<<n<<endl;
    debugA(ans);cout<<endl;
    return 0;
}