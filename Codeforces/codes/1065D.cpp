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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 505
#define INF 10000
// %

int n, m, a, b, t, q, ok, cnt, T[] = {-2, -1, 1, 2};
lli k, r, x, y, z, ans;
pair< int, int > dis[MAXC][MAXC];

int ch(int x, int y, int p){
    return x*n*3 + y*3 + p;
}
bool valid(int i, int j){
    return i>=0&&j>=0&&i<n&&j<n;
}
pair<int, int> operator+(pair< int, int > &p1, pair< int, int > &p2){
    return {p1.fi+p2.fi, p1.se+p2.se};
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector< pair< int, int > > pos(n*n);
    pair< int, int > dp[n*n][3];
    FOR(i, n){
        FOR(j, n){
            cin >> a;
            pos[a-1] = {i, j};
        }
    }
    FOR(i, MAXC){
        FOR(j, MAXC){
            dis[i][j] = i==j?make_pair(0, 0):make_pair(INF, INF);
        }
    }
    FOR(i, n){
        FOR(j, n){
            FOR(dx, 4){
                FOR(dy, 4){
                    if(abs(T[dx]) != abs(T[dy])){
                        int x = i + T[dx], y = j + T[dy];
                        if(valid(x, y)){
                            dis[ch(i, j, 0)][ch(x, y, 0)] = {1, 0};
                        }
                    }
                }
            }
            FOR(k, n){
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(x && y){
                            int fx = i + (k+1)*x, fy = j + (k+1)*y;
                            if(valid(fx, fy)){
                                dis[ch(i, j, 1)][ch(fx, fy, 1)] = {1, 0};
                            }
                        }
                    }
                }
            }
            FOR(k, n){
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        if(abs(x) + abs(y) == 1){
                            int fx = i + (k+1)*x, fy = j + (k+1)*y;
                            if(valid(fx, fy)){
                                dis[ch(i, j, 2)][ch(fx, fy, 2)] = {1, 0};
                            }
                        }
                    }
                }
            }
            FOR(k1, 3){
                FOR(k2, 3){
                    if(k1 != k2){
                        dis[ch(i, j, k1)][ch(i, j, k2)] = {1, 1};
                    }
                }
            }
        }
    }
    FOR(k, ch(n-1, n-1, 3)){
        FOR(s, ch(n-1, n-1, 3)){
            FOR(t, ch(n-1, n-1, 3)){
                dis[s][t] = min(dis[s][t], dis[s][k] + dis[k][t]);
            }
        }
    }
    FOR(i, n*n-1){
        FOR(k, 3){
            dp[i+1][k] = {INF, INF};
        }
        FOR(j, 3){
            FOR(k, 3){
                dp[i+1][k] = min(dp[i+1][k], dp[i][j] + dis[ch(pos[i].fi, pos[i].se, j)][ch(pos[i+1].fi, pos[i+1].se, k)]);
            }
        }
    }
    auto ans = *min_element(dp[n*n-1], dp[n*n-1]+3);
    cout << ans.fi << ' ' << ans.se << '\n';
}