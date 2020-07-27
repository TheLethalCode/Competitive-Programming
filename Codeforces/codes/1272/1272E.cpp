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
void solve(int m, vi &ar, vi &ans, vector< vi > &reach)
{
    queue<int> q; vi vis(n, -1);
    FOR(i,n) if(ar[i]%2==m) q.push(i), vis[i]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : reach[u])
            if(vis[v]==-1)
                vis[v] = vis[u]+1, q.push(v);
    }
    FOR(i, n) if(ar[i]%2==1-m) ans[i]=vis[i];
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    vi v(n), ans(n, -1);
    FOR(i, n) cin>>v[i];
    vector< vi > reach(n);
    FOR(i, n){
        if(i-v[i] >= 0) reach[i-v[i]].pb(i);
        if(i+v[i] <= n-1) reach[i+v[i]].pb(i);
    }
    solve(0, v, ans, reach), solve(1, v, ans, reach);
    debugA(ans);
}