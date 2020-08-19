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
#define MAXC 2005
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    lli w;
    vector < lli > V(n), lo(n+1), hi(n+1);
    cin >> n >> w;
    FOR (i, n) {
        cin >> V[i];
    }
    lo[n] = 0, hi[n] = w;
    for (int i = n-1; i >= 0; i--) {
        if (V[i] < 0) {
            lo[i] = lo[i+1] - V[i];
            hi[i] = min(w, hi[i+1] - V[i]); 
        } else {
            hi[i] = hi[i+1] - V[i];
            lo[i] = max(0LL, lo[i+1] - V[i]);
        }
        if (lo[i] > w || hi[i] < 0 || lo[i] > hi[i]) {
            cout << "0\n";
            return 0;
        }
    }
    cout << hi[0] - lo[0] + 1 << '\n'; 
}