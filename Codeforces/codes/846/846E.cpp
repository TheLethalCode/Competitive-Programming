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

int n, m, a, b, t, q, ok, cnt;
lli k, r, x, y, z, ans;
const lli M = 1e18;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector< lli > A(n+1), B(n+1);
    vector< pair< lli, int > > V(n+1);
    int out[n+1] = {};
    FOR(i, n){
        cin >> B[i+1];
    }
    FOR(i, n){
        cin >> A[i+1];
    }
    for(int i=2;i<=n;i++){
        cin >> a >> x;
        V[i] = {a, x};
        out[a]++; 
    }
    queue< int > q;
    FOR(i, n){
        if(!out[i+1]){
            q.push(i+1);
        }
    }
    while(q.size()){
        int u = q.front(), v = V[u].fi;
        out[v]--;
        if(!out[v] && v!=1){
            q.push(v);
        }
        q.pop();
        if(B[u] >= A[u]){
            B[v] += B[u] - A[u]; 
        }
        else{
            lli req = A[u] - B[u], k = V[u].se;
            if(M/req < k || B[v] - req*k < -M){
                ok = 1;
                break;
            }
            B[v] -= req*k;
        }
    }
    cout << (ok || A[1]>B[1]?"NO" : "YES") << '\n';
}