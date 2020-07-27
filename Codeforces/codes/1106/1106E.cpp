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
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

struct data{ int s, t, d, w;}v[100005];
struct comp{
    bool operator()(int i, int j){
        if(v[i].w == v[j].w) {
            if(v[i].d == v[j].d) return i < j;
            return v[i].d > v[j].d;
        }
        return v[i].w > v[j].w;
    }
};

lli dp[100005][201];
int env[100005], n, m, k;

lli solve(int st, int dis){
    if(dp[st][dis]!=-1) return dp[st][dis];
    if(st==n+1) return dp[st][dis]=0;
    dp[st][dis] = env[st]!=-1?v[env[st]].w + solve(v[env[st]].d+1, dis):solve(st+1, dis);
    if(dis > 0) dp[st][dis] = min(dp[st][dis], solve(st+1, dis-1));
    return dp[st][dis];
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m>>k;
    vpa events[n+2];
    FOR(i, k) {
        cin>>v[i].s>>v[i].t>>v[i].d>>v[i].w;
        events[v[i].s].pb(0, i);
        events[v[i].t+1].pb(1, i);
    }
    FOR(i, n+2) FOR(j, m+1) dp[i][j]=-1, env[i]=-1;
    set< int, comp > s;
    FOR(i, n+1){
        FORR(el, events[i+1]) {
            if(!el.fi) s.insert(el.se);
            else s.erase(el.se);
        }
        if(sz(s)) env[i+1] = *s.begin();
    }
    cout<<solve(1, m)<<endl;
}