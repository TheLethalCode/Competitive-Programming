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

// %

vi sdis, ddis;

bool comp(int lhs, int rhs)
{
    return sdis[lhs] - ddis[lhs] < sdis[rhs] - ddis[rhs];
}

void bfs(int u, vi &vis, vector< vi > &v)
{
    queue<int> q;
    q.push(u);
    vis[u] = 0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int r: v[u])
        {
            if(vis[r] != -1)
                continue;
            vis[r] = vis[u]+1;
            q.push(r);
        }
    }
}

int main(int argc, char **argv)
{
    crap;
    int n,m,k;
    cin>>n>>m>>k;
    vector< vi > v(n+1);
    vi sp(k);
    FOR(i,k)
        cin>>sp[i];
    FOR(i,m)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b), v[b].pb(a);
    }
    sdis.resize(n+1,-1), ddis.resize(n+1,-1);
    bfs(1, sdis, v), bfs(n, ddis, v);
    sort(all(sp), comp);

    vi suff(k);
    set<int> te;
    FOR(i,k)
    {
        te.insert(ddis[sp[k-1-i]]);
        suff[k-1-i] = *te.rbegin();
    }

    int ans = 0;
    FOR(i,k-1)
        ans = max(ans, sdis[sp[i]]+suff[i+1]);

    cout<<min(ans+1, sdis[n])<<endl;
}