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

// %

int main(int argc, char **argv)
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n,m;
        cin>>n>>m;
        
        lli N = n + 1;
        lli a = N/(m+1), rem = N - a*(m+1), b = a + 1;
        lli ans = rem*b*N + (m-rem)*a*N;
        ans -= (m-rem)*rem*b*a + rem*(rem+1)/2 * b*b + (m-rem)*(m-rem+1)/2 * a*a;
        cout<<ans<<endl; 
    }
}