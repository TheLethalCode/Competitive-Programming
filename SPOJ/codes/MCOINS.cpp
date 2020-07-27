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

int K,L;
vi v(1000001,-1);

int dp(int n)
{
    if(n==1 || n==K  || n==L)
        return 1;
    if(v[n]!=-1)
        return v[n];
    if(!((v[n-1]==-1)?dp(n-1):v[n-1]))
        return v[n] = 1;
    if(n < K)
        return v[n] = 0;

    if(!((v[n-K]==-1)?dp(n-K):v[n-K]))
        return v[n] = 1;
    if(n < L)
        return v[n] = 0;

    if(!((v[n-L]==-1)?dp(n-L):v[n-L]))
        return v[n] = 1;
    return 0;
}

int main(int argc, char **argv)
{
    crap;
    int m;
    cin>>K>>L>>m;
    v[1] = v[K] = v[L] = 1;
    string ans="";
    FOR(i,m)
    {
        int x;
        cin>>x;
        ans+=dp(x)?'A':'B';
    }
    cout<<ans;
    nl;
}