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
#define mp make_pair

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define MAXC 200005
// %

vi ed[MAXC], cyc;
int par[MAXC], tin[MAXC], tout[MAXC], col[MAXC], ti=0, st=-1, en=-1;

bool is_anc(int x, int y){
    if(tin[x]<=tin[y] && tout[y]<=tout[x])
        return true;
    return false;
}

void dfs(int u, int p, int c){
    par[u]=p, tin[u]=ti++, col[u]=c;
    for(int v : ed[u]){
        if(v==par[u]) continue;
        if(par[v]!=-1) st = v, en = u;
        else dfs(v, u, !c);
    }
    tout[u]=ti++;
}

int main(int argc, char **argv)
{
    crap;
    int n, m, k;
    cin>>n>>m>>k;
    FOR(i, n) par[i+1]=-1;
    FOR(i, m){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }

    dfs(1, 0, 0);
    if(st==-1){
        int x = 0, y = 0;
        cout<<1<<endl;
        FOR(i, n) (col[i+1]?x:y)++;
        for(int i=1, count=0;i<=n && count<(k+1)/2;i++)
            if(col[i]==(x>y)) cout<<i<<" ", count++;
        cout<<endl;
        return 0;
    }

    while(!is_anc(st, en)) cyc.pb(st), st=par[st];
    cyc.pb(st), reverse(all(cyc));
    while(en != st) cyc.pb(en), en=par[en];
    
    if(cyc.size()<=k){
        cout<<2<<endl;
        cout<<cyc.size()<<endl;
        debugA(cyc);
        return 0;
    }

    map<int, int> mp;
    int r = cyc.size(), len=r, e1 = 0, e2 = r-1;
    FOR(i, r) mp[cyc[i]]=i; 
    for(int te : cyc){
        for(int to : ed[te]){
            if(!mp.count(to)) continue;
            int x = mp[te], y = mp[to], z = min(abs(y-x), r-abs(y-x));
            if(z==1 || z > len) continue;
            len = z+1, e1 = x, e2 = y;
        }
    }

    if(e1>e2) swap(e1, e2);
    if(len <= k){
        cout<<2<<endl;
        cout<<len<<endl;
        if(e1+len-1 == e2) for(int i=e1;i<=e2;i++) cout<<cyc[i]<<" ";
        else for(int i=0;i<len;i++) cout<<cyc[(e2+i)%r]<<" ";
        cout<<endl;
    }
    else{
        cout<<1<<endl;
        for(int i=0;i<(k+1)/2;i++){
            if(e1+len-1 == e2) cout<<cyc[e1+2*i]<<" ";
            else cout<<cyc[(e2+2*i)%r]<<" ";
        }
        cout<<endl;
    }
}