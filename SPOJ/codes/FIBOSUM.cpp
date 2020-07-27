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

typedef struct test
{
    lli V[2][2];
    test(lli a)
    {
        V[0][0]=1;V[1][1]=!a;
        V[1][0]=V[0][1]=a;
    }
    test()
    {
        FOR(i,2)
            FOR(j,2)
                V[i][j]=0;
    }
}matrix;

matrix I(0);
matrix M(1);

matrix operator *(matrix L, matrix R)
{
    matrix te;
    FOR(i,2)
        FOR(j,2)
            FOR(k,2)
                te.V[i][j]+=L.V[i][k]*R.V[k][j],te.V[i][j]%=mod;
    return te;
}

matrix modpow(lli n)
{
    if(!n)
        return I;
    else if(n&1)
        return modpow(n-1)*M;
    matrix t=modpow(n>>1);
    return t*t;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        lli n,m;
        cin>>n>>m;
        matrix L=modpow(m+1),R=modpow(n);
        cout<<(L.V[0][0]-R.V[0][0]+mod)%mod;nl;
    }
}