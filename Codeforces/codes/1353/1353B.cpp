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

#define nl cout<<endl;
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
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vi a(n), b(n);
        FOR(i, n) cin>>a[i];
        FOR(i, n) cin>>b[i];
        sort(all(a));
        sort(all(b));
        int i = 0 , j=n-1;
        while(i < k && a[i] < b[j])
            a[i++] = b[j--];
        lli sum = 0;
        for(int i=0; i<n; i++)
            sum+=a[i];
        cout<<sum<<endl;
    }
}