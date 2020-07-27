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
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int n, m;

lli solve(vector< lli > &pref){
    for(int j=0; j<m-1; j++){
        for(int i=1; i<sz(pref); i++){
            pref[i] = (pref[i] + pref[i-1]) % mod;
        }
    }
    return pref.back();
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    lli ans = 0;
    vector< lli > cnt(n+1);
    for(int i=1; i<=n; i++){
        vector< lli > temp(i, 1);
        cnt[i] = solve(temp);
    }
    for(int b = 1; b <= n; b++){
        for(int a = 1; a <= b; a++){
            ans = (ans + cnt[a] * cnt[n-b+1] % mod) % mod;     
        }
    }
    cout << ans << '\n';
}