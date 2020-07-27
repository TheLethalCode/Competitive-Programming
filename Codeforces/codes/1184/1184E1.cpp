#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair< int, pair<int,int> >
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
vi par, siz;
int n, m;
pa qw;

int fiP(int x){
    if(par[x]==x)
        return x;
    return par[x] = fiP(par[x]);
}

void uni(int x, int y){
    int a = fiP(x), b= fiP(y);
    if(siz[a] < siz[b])
        swap(a, b);
    par[b] = a, siz[a]+=siz[b];
}

bool can(int ans, set< pa > &temp)
{
    FOR(i, n) par[i+1]=i+1, siz[i+1]=1;
    temp.erase(qw);temp.insert({ans, {qw.se.fi, qw.se.se}});
    int ch=0;
    for(auto edge : temp){
        int x = fiP(edge.se.fi), y = fiP(edge.se.se);
        if(x==y) continue;
        uni(x, y), ch+=edge.fi;
        if(siz[fiP(1)]==n) break;
    }

    FOR(i, n) par[i+1]=i+1, siz[i+1]=1;
    uni(qw.se.fi, qw.se.se);
    temp.erase({ans, {qw.se.fi, qw.se.se}});   
    
    int ch1 = ans;
    for(auto edge : temp){
        int x = fiP(edge.se.fi), y = fiP(edge.se.se);
        if(x==y) continue;
        uni(x, y), ch1+=edge.fi;
        if(siz[fiP(1)]==n) break;
    }
    temp.insert(qw);
    return ch1==ch;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    par.resize(n+1), siz.resize(n+1);
    set< pa > ed;
    FOR(i, m){
        int a, b, c;
        cin>>a>>b>>c;
        ed.insert({c, {a, b}});
        if(!i)
            qw={c,{a, b}};
    }
    int ans = 0;
    for(int i=29;i>=0;i--){
        if(can(ans+(1<<i), ed))
            ans+=1<<i;
    }
    cout<<min(ans, mod-7)<<endl;
}