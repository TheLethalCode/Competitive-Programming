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

// %
int n, m, a, b, c, fl=0, vis[5001], col[10001];
vi ed[5001];

void dfs(int u, int c){
    vis[u]=c, col[c]++;
    for(int v : ed[u]){
        if(vis[v] == c) fl=1;
        if(vis[v] != -1) continue;
        dfs(v, c^1);
    }
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m>>a>>b>>c;
    FOR(i, m){
        int x, y;
        cin>>x>>y;
        ed[x].pb(y), ed[y].pb(x);
    }
    FOR(i, n+1) vis[i]=-1, col[i]=0;
    int cnt=0;
    FOR(i, n){
        if(vis[i+1]!=-1) continue;
        dfs(i+1, cnt);
        cnt+=2;
    }
    if(fl){
        cout<<"NO"<<endl;
        return 0;
    }
    vector< vector< short > > mp(cnt>>1, vector< short >(5001, -1));
    mp[0][col[0]] = 0, mp[0][col[1]] = 1; 
    for(int i=1;i<cnt/2;i++){
        FOR(j, 5001){
            if(mp[i-1][j]==-1) continue;
            mp[i][j+col[2*i]]=2*i;
            mp[i][j+col[2*i+1]]=2*i+1;
        }
    }
    vi ans(cnt, 0);
    if(mp[cnt/2-1][b] != -1){
        int prev = b;
        for(int i=cnt/2-1;i>=0;i--){
            int which = mp[i][prev];
            ans[which]=1, prev-=col[which];
        }
        string fin(n, '0');
        FOR(i, n) if(ans[vis[i+1]]) fin[i]='2';
        FOR(i, n) {
            if(fin[i]=='0' && a) fin[i]='1', a--;
            else if(fin[i]=='0') fin[i]='3', c--;
        }
        cout<<"YES"<<endl;
        cout<<fin<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return 0;
}