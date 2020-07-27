#include<bits/stdc++.h>
using namespace std;

#define mod 998244353
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

// %

int main(int argc, char **argv)
{
    crap;
    lli n,k;
    cin>>n>>k;
    vi v(n);
    FOR(i, n) cin>>v[i];
    if(k==1)
    {
        cout<<n<<" "<<1<<endl;
    }
    else
    {
        lli ans=1, temp=-1;
        for(int i=0;i<n;i++)
        {
            if(v[i]>n-k & temp==-1)
                temp=i;
            else if(v[i]>n-k)
            {
                ans *= (i-temp), ans %= mod;
                temp=i;
            }
        }
        cout<<n*(n+1)/2 - (n-k)*(n-k+1)/2<<" "<<ans<<endl;
    }
}