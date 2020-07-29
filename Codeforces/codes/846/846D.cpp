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
#define MAXC 200005
// %

int n, m, a, b, t = -1, q, ok, cnt;
lli k, r, x, y, z, ans;
vector< pair< int, pair< int, int > > > B;

bool can(int cur){
    int sc[n][m], sum[n+1][m+1];
    memset(sc, 0, sizeof sc);
    memset(sum, 0, sizeof sum);
    for(int i=0;i<=cur;i++){
        sc[B[i].se.fi-1][B[i].se.se-1] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            sum[i+1][j+1] = sum[i+1][j] + sc[i][j];
        }
        for(int j=0;j<m;j++){
            sum[i+1][j+1] += sum[i][j+1];
        }
    }
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            int val = sum[i][j] - sum[i-k][j] - sum[i][j-k] + sum[i-k][j-k];
            if(val == k*k){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> q;
    B.resize(q);
    FOR(i, q){
        cin >> B[i].se.fi >> B[i].se.se >> B[i].fi;
    }
    sort(B.begin(), B.end());
    int lo = 0, hi = q-1, mid;
    while(lo<=hi){
        if(can(mid=lo+hi>>1)){
            hi = mid-1;
            t = B[mid].fi;
        }
        else{
            lo = mid+1;
        }
    }
    cout << t << '\n';
}