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
int solve(vector< int > &v){
    int n = v.size(), cnt = 0, d = v[1] - v[0];
    for (int i = 2; i < n; i++) {
        if (abs(v[i] - v[i-1] - d) > 1) {
            return mod;
        } 
        cnt += (v[i] != v[i-1] + d);
        v[i] = v[i-1] + d;
    }
    return cnt;
}
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector< int > v(n);
    FOR (i, n) {
        cin >> v[i];
    }
    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }
    int ans = mod;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            auto temp = v;
            temp[0] += i;
            temp[1] += j;
            ans = min(ans, abs(i) + abs(j) + solve(temp));
        }
    }
    cout << (ans == mod? -1 : ans) << '\n';
}