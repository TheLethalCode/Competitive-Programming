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

vector< string > v;

int h,w;
int ma=0;
vector< vector< bool > > vis;

bool isvalid(int i,int j)
{
    if(i<0 || i>=h || j<0 || j>=w)
        return false;
    return true;
}

void dfs(int x,int y,int cnt)
{
    vis[x][y]=true;
    ma=max(ma,cnt);
    for(int i=x-1;i<=x+1;i++)
        for(int j=y-1;j<=y+1;j++)
            if(isvalid(i,j) && !vis[i][j] && v[i][j]==v[x][y]+1)
                dfs(i,j,cnt+1);

}

int main(int argc, char **argv)
{
    crap;
    cin>>h>>w;
    int cnt=0;
    while(h)
    {
        cnt++;
        v.resize(h);
        vis.resize(h,vector< bool >(w,false));
        FOR(i,h) cin>>v[i];
        FOR(i,h)
            FOR(j,w)
                if(v[i][j] == 'A')
                    dfs(i,j,1);
        cout<<"Case "<<cnt<<": "<<ma;nl;
        ma=0;
        v.clear();
        vis.clear();
        cin>>h>>w;
    }
}