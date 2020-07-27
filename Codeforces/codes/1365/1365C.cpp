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
#define mp make_pair

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
    int n;
    cin>>n;
    vi A(n+1), B(n+1);
    FOR(i, n) {
        int a;cin>>a;
        A[a]=i+1;
    }
    FOR(i, n) {
        int a;cin>>a;
        B[a]=i+1;
    }
    map< int, int > mp;
    FOR(i, n) {
        int dis = (A[i+1]-B[i+1]+n)%n;
        if(mp.count(dis)) mp[dis]++;
        else mp[dis]=1;
    }

    int ans=0;
    for(auto el : mp)
        ans=max(ans, el.se);
    cout<<ans<<endl;
}