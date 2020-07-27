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
int n, m, t, dis[1001][1001];
char v[1001][1001];

bool check(int i, int j){
    if(i>0 && v[i-1][j] == v[i][j])
        return true;
    if(i<n-1 && v[i+1][j] == v[i][j])
        return true;
    if(j>0 && v[i][j-1] == v[i][j])
        return true;
    if(j<m-1 && v[i][j+1] == v[i][j])
        return true;
    return false;
}

bool valid(int i, int j){
    return (i>=0&&j>=0&&i<n&&j<m);
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m>>t;
    FOR(i, n) FOR(j, m) cin>>v[i][j];
    FOR(i, n) FOR(j, m) dis[i][j] = -1;
    
    FOR(i, n) FOR(j, m){
        if(dis[i][j]!=-1 || !check(i, j)) continue;
        queue< pa > q;
        q.push({i, j});dis[i][j]=0;
        while(!q.empty()){
            int ux = q.front().fi, uy=q.front().se;
            q.pop();

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(i-j)!=1)continue;
                    int vx = ux+i, vy=uy+j;
                    if(!valid(vx, vy) || dis[vx][vy]!=-1) continue;
                    if(v[vx][vy]!=v[ux][uy]) continue;
                    dis[vx][vy]=0, q.push({vx, vy});
                }
            }
        }
    }
    
    queue< pa > q;
    FOR(i, n) FOR(j, m) if(!dis[i][j]) q.push({i, j});
    while(!q.empty()){
        int ux = q.front().fi, uy=q.front().se;
        q.pop();

        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(abs(i-j)!=1)continue;
                int vx = ux+i, vy=uy+j;
                if(!valid(vx, vy) || dis[vx][vy]!=-1) continue;
                dis[vx][vy]=dis[ux][uy]+1, q.push({vx, vy});
            }
        }
    }

    while(t--){
        int i, j, cur;
        lli p;
        cin>>i>>j>>p;
        i--, j--, cur = v[i][j]-'0';
        if(dis[i][j] == -1 || dis[i][j]>=p) cout<<cur<<endl;
        else cout<<(cur+((p-dis[i][j])&1))%2<<endl;
    }
}