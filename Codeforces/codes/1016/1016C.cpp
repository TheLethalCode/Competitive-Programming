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
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y<<", "
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;

    vli a(n),b(n);
    FOR(i,n) cin>>a[i];
    FOR(i,n) cin>>b[i];

    vpal dp1(n),dp2(n);

    lli ans = 0;
    for(int i=0;i<n;i++)
    {
        if(!i)
        {
            dp1[i].fi = b[n-1], dp1[i].se = a[n-1] + b[n-1];
            dp2[i].fi = a[n-1], dp2[i].se = a[n-1] + b[n-1];
        }

        else
        {
            pal r1 = { (dp1[i-1].fi + dp1[i-1].se) + (2*i + 1)*b[n-1-i], a[n-1-i] + dp1[i-1].se + b[n-1-i]} ;
            dp1[i] = r1;
            r1 = { (dp2[i-1].fi + dp2[i-1].se) + (2*i + 1)*a[n-1-i], a[n-1-i] + dp2[i-1].se + b[n-1-i]} ;
            dp2[i] = r1;
        }
    }
    lli cnt = 0, temp=0;
    for(int i=0;i<n;i++)
    {
        ans = max(ans, temp + dp1[n-1-i].fi + cnt*dp1[n-1-i].se);
        temp += cnt*a[i] + (cnt+1)*b[i],cnt+=2;

        if(i!=n-1)
        {
            ans = max(ans, temp + dp2[n-2-i].fi + cnt*dp2[n-2-i].se), i++;
            temp += cnt*b[i] + (cnt+1)*a[i],cnt+=2;
        }
    }
    cout<<ans<<endl;
}