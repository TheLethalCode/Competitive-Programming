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

int n;

bool isval(int i,int j)
{
    if(i>=n || j>=3 || i<0 || j<0)
        return false;
    return true;
}

vector< vli > dp,v;

lli calc(int i,int j)
{
    if(i==n-1 && j==1)
        return v[i][j];
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    lli val=1e9;
    if(i==n-1)
    {
        if(j==0)
            return dp[i][j] = v[i][j] + calc(i,1);
        else
            return 1e9;
    }
    else if(j==0)
    {
        val = min3(calc(i,1),calc(i+1,0),calc(i+1,1));
        return dp[i][j] = v[i][j] + val;
    }
    else if(j==1)
    {
        val = min3(calc(i,2),calc(i+1,0),calc(i+1,1));
        val = min(val,calc(i+1,2));
        return dp[i][j] = v[i][j] + val;
    }
    else
    {
        val = min(calc(i+1,2),calc(i+1,1));
        return dp[i][j] = v[i][j] + val;
    }
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    int cnt=0;
    while(n)
    {
        cnt++;
        v.clear();
        v.resize(n,vli(3));
        dp.clear();
        dp.resize(n,vli(3,-1));
        FOR(i,n)
            FOR(j,3)
                cin>>v[i][j];
        cout<<cnt<<". "<<calc(0,1);nl;
        cin>>n;
    }
}