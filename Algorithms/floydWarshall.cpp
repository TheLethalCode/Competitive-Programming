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
#define INF 1e18
// %

int n;
lli adjList[MAXC][MAXC], dis[MAXC][MAXC];

void floydWarshall(){
    FOR(i, n){
        FOR(j, n){
            dis[i][j] = adjList[i][j];
        }
    }
    FOR(k, n){
        FOR(i, n){
            FOR(j, n){
                if(dis[i][k] < INF && dis[k][j] < INF){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);   
                }
            }
        }
    }
}