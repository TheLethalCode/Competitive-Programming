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
pa des[1001][1001];
pa par[1001][1001];
char ans[1001][1001];
int n;

bool val(int i, int j){
    return i>=0&&j>=0&&i<n&&j<n;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n;
    
    FOR(i, n) FOR(j, n) {
        cin>>des[i][j].fi>>des[i][j].se;
        des[i][j].fi--, des[i][j].se--;
        ans[i][j] = '0', par[i][j]={-1, -1};
    }
    
    map< char, pa > mp, mpb;
    mp['L'] = {0,1}, mp['R']={0,-1}, mp['U']={1,0}, mp['D']={-1,0};
    mpb['R'] = {0,1}, mpb['L']={0,-1}, mpb['D']={1,0}, mpb['U']={-1,0};

    FOR(i, n) FOR(j, n){
        if(des[i][j]!=make_pair(i, j)) continue;
        queue< pa > q; q.push({i, j});
        ans[i][j] = 'X';
        while(!q.empty()){
            int ux = q.front().fi, uy = q.front().se;
            q.pop();
            for(auto el : mp){
                int vx = ux + el.se.fi, vy = uy + el.se.se;
                if(!val(vx, vy) || par[ux][uy]==make_pair(vx, vy) || des[vx][vy] != des[ux][uy]) continue;
                if(ans[vx][vy]!='0') continue;
                ans[vx][vy] = el.fi, q.push({vx, vy}), par[vx][vy]={ux, uy};
            }
        }
    }
    FOR(i, n) FOR(j, n) {
        if(ans[i][j]=='0' && des[i][j]!=make_pair(-2, -2)){
            cout<<"INVALID"<<endl;
            return 0;
        }
    }
    FOR(i, n) FOR(j, n){
        if(ans[i][j]=='0'){
            for(auto el : mpb){
                int x = el.se.fi+i, y=el.se.se+j;
                if(!val(x, y) || des[x][y]!=make_pair(-2, -2)) continue;
                ans[i][j] = el.fi;
            }
            if(ans[i][j]=='0'){
                cout<<"INVALID"<<endl;
                return 0;
            }
        }
    }
    cout<<"VALID"<<endl;
    FOR(i, n){
        FOR(j, n) cout<<ans[i][j];
        cout<<endl;
    }
}