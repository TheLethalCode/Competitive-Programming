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

void dfs(int i, int j, vector< string > &v, vector< vi > &vis)
{
    int n = v.size(), m = v[0].size();
    for(int a=0;a <= 1;a++)
        for(int b=0;b<=1;b++)
            if(abs(a) + abs(b) == 1)
                if(i+a < n && j+b < m)
                    if(vis[i+a][b+j] == -1 && v[i+a][b+j] == '.')
                        vis[i+a][b+j] = vis[i][j] + 1, dfs(i+a, b+j, v, vis);

}

void dfs1(int i, int j, vector< string > &v, vector< vector< bool> > &vis)
{
    for(int a=0;a <= 1;a++)
        for(int b=0;b<=1;b++)
            if(abs(a) + abs(b) == 1)
                if(i-a >= 0 && j-b >= 0)
                    if(!vis[i-a][j-b]  && v[i-a][j-b] == '.')
                        vis[i-a][j-b] = true, dfs1(i-a, j-b, v, vis);

}


int main(int argc, char **argv)
{
    crap;
    int n,m;
    cin>>n>>m;

    vector< string > v(n);
    FOR(i,n) cin>>v[i];
    
    // Start
    vector< vi > vis(n,vi(m,-1));
    vector< vector< bool > > vis1(n,vector<bool>(m,false));
    vis[0][0] = 0;
    dfs(0, 0, v, vis);

    vis1[n-1][m-1] = true;
    dfs1(n-1, m-1, v, vis1);

    vi cnt(1e6+1,0);
    FOR(i,n)
        FOR(j,m)
            if(vis[i][j] != -1 && vis1[i][j])
                cnt[vis[i][j]]++;

    int fl = 0;
    for(int i=1;i<n+m-2;i++)
        if(cnt[i] == 1)
            fl = 1;

    if(vis[n-1][m-1] == -1)
        cout<<0<<endl;
    else if(fl)
        cout<<1<<endl;
    else
        cout<<2<<endl;   
}