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
int dis[51][51];
int n, m;

bool val(int i, int j){
    return i>=0&&j>=0&&i<n&&j<m;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vpa pos[2];
        vector< string > v(n, "");
        FOR(i, n) FOR(j, m){
            dis[i][j]=-1;
            char a;cin>>a;
            v[i]+=a;
            if(a=='#') dis[i][j]=1;
            else if(a=='G') pos[0].pb({i, j});
            else if(a=='B') pos[1].pb({i, j});
        }
        if(pos[0].empty()){
            cout<<"Yes"<<endl;
            continue;
        }

        int fl=0;
        for(pa el : pos[1]){
            for(int i=-1;i<=1 && !fl;i++){
                for(int j=-1;j<=1 && !fl;j++){
                    if(abs(i-j)!=1 || !val(el.fi+i, el.se+j)) continue;
                    int x = el.fi+i, y=el.se+j;
                    if(v[x][y]=='G') fl=1;
                    else if(v[x][y]=='.') dis[x][y]=1;
                }
            }
            if(fl) break;
        }
        if(fl || dis[n-1][m-1]==1){
            cout<<"No"<<endl;
            continue;
        }

        queue< pa > q;
        q.push({n-1, m-1}); dis[n-1][m-1]=0;
        while(!q.empty()){
            pa u = q.front();
            q.pop();
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if(abs(i-j)!=1 || !val(u.fi+i, u.se+j)) continue;
                    int x = u.fi+i, y=u.se+j;
                    if(dis[x][y]>=0) continue;
                    dis[x][y]=0, q.push({x,y});
                }
            }
        }

        FOR(i, n) FOR(j, m){
            if(v[i][j]=='G' && dis[i][j]<0){
                fl=1;
            }
        }
        if(fl) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}