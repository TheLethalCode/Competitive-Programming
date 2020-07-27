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
lli dis[1001][1001], col[1001], row[1001];
int n, m;

bool check(int i, int j){
    return i>=0&&j>=0&&i<n&&j<m&&dis[i][j]==-1;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>m;
    queue< pa > q;
    int temp=0;
    FOR(i, n) FOR(j, m) {
        row[i]=0, col[j]=0;
        char a; cin>>a;
        if(a == '#') dis[i][j]=-1;
        else dis[i][j]=0, temp++;
    }
    if(temp == n*m || !temp){
        cout<<(temp==n*m?0:1)<<endl;
        return 0;
    }
    int cnt=1;
    FOR(i, n) FOR(j, m){
        if(dis[i][j]!=-1) continue;
        q.push({i, j});dis[i][j]=cnt;
        while(!q.empty()){
            int x = q.front().fi, y = q.front().se;
            q.pop();
            for(int i=-1;i<=1;i++)
                for(int j=-1;j<=1;j++){
                    if(abs(i-j)!=1 || !check(x+i, y+j)) continue;
                    dis[x+i][y+j]=cnt, q.push({x+i, y+j});
                }
        }
        cnt++;
    }
    FOR(i, n) FOR(j, m) col[j]+=dis[i][j], row[i]+=dis[i][j];

    FOR(i, n){
        vi temp; int fl=0;
        FOR(j, m){
            if(dis[i][j]) {
                if(!temp.empty() && temp.back() != j-1){
                    cout<<-1<<endl;
                    return 0;
                }
                temp.pb(j);
            }
            fl |= (col[j]==0);
        }
        if(temp.empty() && !fl){
            cout<<-1<<endl;
            return 0;
        }
    }
    FOR(j, m){
        vi temp;int fl=0;
        FOR(i, n){
            if(dis[i][j]) {
                if(!temp.empty() && temp.back() != i-1){
                    cout<<-1<<endl;
                    return 0;
                }
                temp.pb(i);
            }
            fl |= (row[i]==0);
        }
        if(temp.empty() && !fl){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<cnt-1<<endl;
}