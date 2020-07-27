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
#define debugA(v,n) for(int i=0;i<n;i++) cout<<v[i]<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    int n,m;
    cin>>n>>m;
    vector< vi > A(n,vi(m)),B(n,vi(m));
    FOR(i,n) FOR(j,m) cin>>A[i][j];
    FOR(i,n) FOR(j,m) cin>>B[i][j];
    int fl=1;
    vector< vi > Aa(n+m-1),Bb(n+m-1);
    FOR(i,n)
        FOR(j,m)
        {
            Aa[i+j].pb(A[i][j]);
            Bb[i+j].pb(B[i][j]);
        }
    FOR(i,n+m-1)
    {
        sort(all(Aa[i]));
        sort(all(Bb[i]));
        for(int j=0; j<Aa[i].size(); j++)
            if(Aa[i][j] != Bb[i][j])
            {
                fl=0;
                break;
            }
    }
    if(fl)
        cout<<"YES";
    else
        cout<<"NO";
    nl;
}