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
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;cout<<endl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int ans[1010][1010][3];

int calc(int i,int j,int k)
{
    if(i<=0 || j<=0)
        return 0;
    if(ans[i][j][k]!=-1)
        return ans[i][j][k];
    int val=0;
    FOR(t,3)
    {
        if(t==k)
            continue;
        val = t? t-1? max(val,calc(i-20,j+5,2)) : max(val,calc(i-5,j-10,1)) : max(val,calc(i+3,j+2,0));
    }
    return ans[i][j][k] = val+1;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        FOR(i,1010)
            FOR(j,1010)
                FOR(k,3)
                    ans[i][j][k]=-1;
        int h,a;
        cin>>h>>a;
        cout<<calc(h+3,a+2,0);
        nl;
    }
}