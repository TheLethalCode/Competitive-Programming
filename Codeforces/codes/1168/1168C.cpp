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
#define MAXC 300005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int n, q, ar[MAXC], R[MAXC][19], ed[MAXC][19];
vector< int > pos[19];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    FOR(i, n){
        cin >> ar[i+1];
        FOR(j, 19){
            if(ar[i+1] & 1<<j){
                pos[j].pb(i+1);
            }
        }
    }
    memset(R, 0x3f, sizeof(R));
    FOR(i, 19){
        for(int j=0;j<sz(pos[i])-1;j++){
            ed[pos[i][j]][i] = pos[i][j+1];
        }
    }
    for(int i=n;i;i--){
        FOR(j, 19){
            if(ar[i]&1<<j){
                R[i][j] = i;
                FOR(k, 19){
                    R[i][k] = min(R[i][k], R[ed[i][j]][k]);
                }
            }
        }
    }
    while(q--){
        int x, y, ok = 0;
        cin >> x >> y;
        FOR(j, 19){
            if((ar[y]&1<<j) && R[x][j]<=y){
                ok = 1;
                break;
            }
        }
        cout << (ok? "Shi" : "Fou") << '\n';
    }
}