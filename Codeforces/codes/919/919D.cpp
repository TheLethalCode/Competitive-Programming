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

vi sn;

int cyclic(int u, vector< set<int> > &ed, vi &vis, vi &rec)
{
    vis[u] = 1, rec[u] = 1;
    for(int v : ed[u])
    {
        if(!vis[v] && cyclic(v,ed,vis,rec))
            return 1;
        if(rec[v])
            return 1;
    }
    rec[u] = 0;
    return 0;
}

void topo(int u, vector< set<int> > &ed, vi &vis)
{
    vis[u]=1;
    for(int v : ed[u])
        if(!vis[v])
            topo(v, ed, vis);
    sn.pb(u);
}

int main(int argc, char **argv)
{
    crap;
    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;
    
    vi ch(n+1);
    vector< set< int > > ed(n+1);
    FOR(i,n) ch[i+1] = s[i]-'a';

    int fl = 0;
    vector< vi > ans(n+1,vi(26,0));
    FOR(i,m)
    {
        int a,b;
        cin>>a>>b;
        fl = (a==b);
        ed[a].insert(b);
    }

    vi visit(n+1,0), rec(n+1,0);
    for(int i=1;i<=n;i++)
        if(!visit[i])
            fl += cyclic(i, ed, visit, rec);

    if(fl)
        cout<<-1<<endl;
    else
    {
        FOR(i,n) visit[i+1] = 0;

        FOR(i,n)
            if(!visit[i+1])
                topo(i+1, ed, visit);
        
        FOR(i,n)
        {
            int u = sn[i];
            for(int v : ed[u])
            {
                for(int j=0;j<26;j++)
                    ans[u][j] = max(ans[u][j],ans[v][j]);
            }
            ans[u][ch[u]]++;
        }

        int fin = 0;
        FOR(i,n)
            FOR(j,26)
                fin = max(fin,ans[i+1][j]);
        cout<<fin<<endl;
    }
}