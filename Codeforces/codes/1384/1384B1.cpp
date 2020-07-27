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
#define MAXC 300005
// %

int n, m, a, b, c, t, ok, V[MAXC];
lli k, r, x, y, z;

lli tide(lli t){
    t %= 2*k;
    return t<=k?t:2*k-t;
}

bool solve(int st, int en){
    lli t = k;
    for(int cur = st; cur < en-1;cur++){
        if( tide(t+1) + V[cur] <= r){
            t = (t+1) % (2*k);
        }
        else if(r-V[cur] >= 0 && t>=k){
            t = (2*k - r + V[cur]) % (2*k) ;   
        }
        else{
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> r;
        m = 0;
        ok = 1;
        FOR(i, n){
            cin >> V[i];
            if(V[i] + k <= r){
                ok &= solve(m, i+1);
                m = i+1;
            }
        }
        ok &= solve(m, n+1);
        cout << (ok?"Yes":"No") << '\n';
    }
}