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
int n, m, a, b;

int bfs(vi &vis, vector< vi > &ed)
{
    int cnt =1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=-1) continue;
        queue<int> q;
        q.push(i), vis[i]=cnt;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : ed[u])
                if(vis[v] == -1)
                    vis[v] = cnt, q.push(v);
        }
        cnt++;
    }
    return cnt-1;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>a>>b;
        vector< vi > ed(n+1);
        FOR(i, m){
            int x, y;
            cin>>x>>y;
            ed[x].pb(y), ed[y].pb(x);
        }

        vi vis(n+1, -1), vis1(n+1, -1);
        vis[a]=0, vis1[b]=0;
        int g1 = bfs(vis, ed), g2 = bfs(vis1, ed);
        
        vector< vi > A(g1+1), B(g2+1);
        FOR(i, n){
            if(i==a-1 || i==b-1) continue;
            A[vis[i+1]].pb(i+1), B[vis1[i+1]].pb(i+1);
        }

        map< pair<int, int>, vi > mp;
        lli ans = 0;
        for(int i=1;i<=n;i++){
            if(i==a || i==b) continue;
            int gr1 = vis[i], gr2 = vis1[i];
            mp[{gr1, gr2}].pb(i);
        }
        for(int i=1;i<=n;i++){
            if(i==a || i==b) continue;
            int gr1 = vis[i], gr2 = vis1[i];
            int x=A[gr1].size(), y=B[gr2].size(), z=mp[{gr1, gr2}].size();
            ans += n-2-x-y+z;
        }
        cout<<ans/2<<endl;
    }
}