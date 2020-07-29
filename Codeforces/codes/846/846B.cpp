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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    vector< lli > v(m);
    lli tot = 0;
    FOR(i, m){
        cin >> v[i];
        tot += v[i];
    }
    sort(v.begin(), v.end());
    FOR(i, n+1){
        if(tot * i > k){
            break;
        }
        lli rem = k - tot*i, temp = (m+1)*i;
        for(int j = 0; j<m; j++){
            lli p = min(rem/v[j], 1LL*n-i);
            temp += p*(1 + (j==m-1));
            rem -= p*v[j];
        }
        ans = max(ans, temp);
    }
    cout << ans << '\n';
}