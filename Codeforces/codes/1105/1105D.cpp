#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int, int>
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

#define cod pair< int, int>
// %
int n, m, p, cnt = 0, s[10];
queue< pa > ca[10];

bool valid(cod po){
    if(po.fi < 0 || po.fi>=n)
        return false;
    if(po.se < 0 || po.se>=m)
        return false;
    return true;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m>>p;
    FOR(i, p) cin>>s[i];
    vector< string > v(n);
    int dis[n+2][m+2];
    FOR(i, n) cin>>v[i];

    FOR(i, n) FOR(j, m) {
        if(v[i][j]!='.' && v[i][j]!='#')
            dis[i][j]=0, ca[v[i][j]-'1'].push({i, j});
        else if(v[i][j]=='.') dis[i][j]=-1;
        else dis[i][j]=1;
    }
    
    while(++cnt){
        int done=0;
        FOR(r, p){
            while(!ca[r].empty()){
                pa u = ca[r].front();
                if(dis[u.fi][u.se] >= 1LL*cnt*s[r]) break;
                ca[r].pop();
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        if(abs(i-j)!=1 || !valid({u.fi+i,u.se+j})) continue;
                        if(v[u.fi+i][u.se+j] != '.') continue;
                        v[u.fi+i][u.se+j] = '1'+r, dis[u.fi+i][u.se+j] = dis[u.fi][u.se]+1;
                        ca[r].push({u.fi+i, u.se+j});
                    }
                }
            }
            if(!ca[r].empty()) done=1;
        }
        if(!done) break;
    }

    vi ans(p, 0);
    FOR(i, n) FOR(j, m) {
        if(v[i][j]!='.' && v[i][j]!='#')
            ans[v[i][j]-'1']++;
    }
    FOR(i, p)
        cout<<ans[i]<<" ";
    cout<<endl;
}