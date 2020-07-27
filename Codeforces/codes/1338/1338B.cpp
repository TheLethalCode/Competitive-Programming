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

int n;
int ban = 0, san=0;

int dfs(int u, vector< vi > &ed, vi &vis)
{
    vis[u]=1;
    int num = 0, cur = 0, fl=0, neg = 0, pas;
    for(int v : ed[u])
    {
        if(vis[v]!=-1)
            continue;
        num++;
        int val = dfs(v, ed, vis);
        pas = val; 
        if(val == 1)
            fl=1;
        else
            cur+=abs(val);
        if(val < 0)
            neg = val;
    }
    if(num==1 && !neg)
        return pas+1;
    else if(num==1)
        return neg-1;
    else if(num)
    {
        ban+= cur + (fl>0);
        return -1;
    }
    return 1;
}

int dfs1(int u, vector< vi > &ed, vi &vis)
{
    vis[u]=1;
    int num = 0, cur=0, odd=0, eve=0;
    for(int v : ed[u])
    {
        if(vis[v]!=-1)
            continue;
        num++;
        int val = dfs1(v, ed, vis);
        cur = val;
        if(val & 1)
            odd++;
        else
            eve++;
    }
    if(num==1)
        return cur+1;
    else if(num)
    {
        if(!eve) 
        {
            san=max(san, 1);
            return 2;
        }
        if(!odd)
        {
            san=max(san, 1);
            return 1;
        }
        san=max(san, 3);
        return 2;
    }
    return 1;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    vector< vi> v(n+1);
    FOR(i, n-1)
    {
        int a, b;
        cin>>a>>b;
        v[a].pb(b), v[b].pb(a);
    }

    vi vis(n+1,-1), vis1(n+1,-1);
    int i = 1;
    while(v[i].size()==1) i++;
    dfs(i, v, vis);
    dfs1(i, v, vis1);
    cout<<san<<" "<<ban<<endl;
}