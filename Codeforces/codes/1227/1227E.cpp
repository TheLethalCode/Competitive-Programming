#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define sz(a) (int)(a.size())
#define MAXC 3000005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int n, m, vis[MAXC], num = 0, T = 0;
bool can(int val, vector< vector< int > > &turn){
    if(val > T){
        return false;
    }
    memset(vis, 0, sizeof(vis));
    int trees = 0;
    queue< pair< int, int > > q;
    for(int i=1; i <= n; i++){
        for(int j=1; j<= m; j++){
            if(turn[i][j] >= val){
                q.push({i, j});
                vis[i*m+j]=1;
                trees++;
            }
        }
    }
    while(trees < num){
        pair< int, int > u = q.front();
        q.pop();
        for(int x=u.fi-1;x<=u.fi+1;x++){
            for(int y=u.se-1;y<=u.se+1;y++){
                if(x!=u.fi || y!=u.se ){
                    if(turn[x][y] == -1){
                        return false;
                    }
                    if(!vis[x*m+y]){
                        q.push({x, y});
                        trees++;
                        vis[x*m+y]=1;
                    }
                }
            }
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int ar[n+2][m+2], cnt[n+2][m+2];
    vector< vector< int > > turn(n+2, vector<int>(m+2, -1));
    FOR(i, n+2){
        FOR(j, m+2){
            ar[i][j] = cnt[i][j] = 0;
        }
    }
    char ch;
    FOR(i, n){
        FOR(j, m){
            cin>>ch;
            ar[i+1][j+1] = ch=='X';
            num += ar[i+1][j+1];
        }
    }
    queue< pair< int, int > > leaf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ar[i][j]){
                turn[i][j]=mod;
                for(int x=i-1;x<=i+1;x++){
                    for(int y=j-1;y<=j+1;y++){
                        if(x!=i || y!=j){
                            cnt[i][j]+=ar[x][y];
                        }
                    }
                }
                if(cnt[i][j]!=8){
                    leaf.push({i, j});
                    turn[i][j] = 0;
                }
            }
        }
    }
    while(!leaf.empty()){
        pair< int, int > u = leaf.front();
        leaf.pop();
        for(int x=u.fi-1;x<=u.fi+1;x++){
            for(int y=u.se-1;y<=u.se+1;y++){
                if(x!=u.fi || y!=u.se ){
                    if(turn[x][y] == mod){
                        turn[x][y] = turn[u.fi][u.se] + 1;
                        leaf.push({x, y});
                        T = max(T, turn[x][y]);
                    }
                }
            }
        }
    }
    int l = 0, r = T, mid, ans;
    while(l <= r){
        mid = l+r>>1;
        if(can(mid, turn)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << "\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << (turn[i][j] >= ans? "X" : ".");
        }
        cout << "\n";
    }
}