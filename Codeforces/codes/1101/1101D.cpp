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
vi ed[MAXC];
int ans = 0, ar[MAXC], sieve[MAXC];

map< int, int > dfs(int u, int p){
    
    map< int, int > len;
    map< int, vi > te;
    int x = ar[u];
    while(x>1){
        int y = sieve[x];
        len[y]=1, ans=max(ans, 1);
        while(x%y==0) x/=y;
    }
    for(int v : ed[u]){
        if(p==v) continue;
        for(pa el : dfs(v, u)){
            if(!len.count(el.fi)) continue;
            te[el.fi].pb(el.se);
        }
    }
    for(auto &el : te){
        sort(el.se.rbegin(), el.se.rend());
        len[el.fi] = max(len[el.fi], el.se[0]+1);
        if(el.se.size()==1) ans = max(ans, el.se[0]+1);
        else ans = max(ans, el.se[0]+el.se[1]+1);
    }
    return len;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    FOR(i, n) cin>>ar[i+1];
    FOR(i, n-1){
        int a, b;
        cin>>a>>b;
        ed[a].pb(b), ed[b].pb(a);
    }
    FOR(i, MAXC) sieve[i]=0;
    for(int i=2;i<MAXC;i++) if(!sieve[i]) for(int j=i;j<MAXC;j+=i) sieve[j]=i;
    dfs(1, -1);
    cout<<ans<<endl;
}