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

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %
#define MAXC 500001

vpal ed[MAXC];
int n, k;

pal dfs(int u, int p){
    vpal var;
    lli tot = 0, cnt=0;
    FORR(v, ed[u]){
        if(v.fi == p) continue;
        pal temp = dfs(v.fi, u);
        var.pb({temp.fi+v.se, temp.se});
        tot += temp.se;
    }
    sort(all(var), [](pal l, pal r){ return l.fi-l.se>r.fi-r.se; });
    pal ret={tot, tot};
    FORR(x, var){
        if(x.fi > x.se) tot += x.fi-x.se, cnt++;
        if(cnt == k-1) ret.fi = tot;
        if(cnt == k) {
            ret.se =  tot;
            break;
        }
    }
    if(cnt < k) ret.fi = ret.se = tot;
    return ret;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        FOR(i, n) ed[i+1].clear();
        FOR(i, n-1){
            int a, b, c;
            cin>>a>>b>>c;
            ed[a].pb({b, c}), ed[b].pb({a, c});
        }
        cout<<dfs(1, -1).se<<endl;
    }
}