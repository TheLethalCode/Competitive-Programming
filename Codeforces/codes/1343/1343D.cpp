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
#define debug1(x) cout<<#x<<" "<<x;cout<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;cout<<endl;
#define debugA(v) for(int i:v) cout<<i<<" ";cout<<endl;
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vi v(n), sa(2*k+1,0);
        FOR(i, n) cin>>v[i];
        FOR(i, n/2) sa[v[i] + v[n-i-1]]++;

        vi sm(n/2), bi(n/2);
        for(int i=0;i<n/2;i++)
            sm[i] = min(v[i], v[n-i-1]), bi[i] = max(v[i], v[n-i-1]) + k + 1;
        sort(all(sm)), sort(all(bi));

        int ans = n/2;
        for(int i=1;i<=2*k;i++)
        {
            if(!sa[i])
                continue;
            int te = n/2 - sa[i];
            te += n/2 - (lower_bound(all(sm), i) - sm.begin());
            te += upper_bound(all(bi), i) - bi.begin();
            ans = min(ans, te);
        }
        cout<<ans<<endl;
    }
}