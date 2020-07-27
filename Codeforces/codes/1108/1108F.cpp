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
#define MAXC 200005
int p[MAXC];
vpa s[MAXC];
int f(int x) { return p[x]==x?x:p[x]=f(p[x]);}
int main(int argc, char **argv)
{
    crap;
    int n, m, ans = 0;
    cin>>n>>m;
    FOR(i, n+1) p[i]=i;
    vector< pair< int , pa > > v(m);
    FOR(i, m) {
        int a, b, w;
        cin>>a>>b>>w;
        v[i] = {w, {a, b}};
        s[a].pb(b, w), s[b].pb(a, w);
    }
    sort(all(v));
    for(int i=0;i<m;i++){
        int a = f(v[i].se.fi), b = f(v[i].se.se), cur = v[i].fi;
        if(a == b) continue;
        if(sz(s[a]) > sz(s[b])) swap(a, b);
        FORR(ed, s[a]){
            if(f(ed.fi)==b && ed.se==cur) ans++;
            else if(f(ed.fi)!=b) s[b].pb(ed);
        }
        p[a] = b;
    }
    cout<<ans-n+1<<endl;
}