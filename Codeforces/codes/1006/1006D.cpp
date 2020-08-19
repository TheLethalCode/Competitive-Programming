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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    string a, b;
    cin >> a >> b;
    FOR (i, n/2) {
        vector< int > temp = {a[i], a[n-1-i], b[i], b[n-1-i]};
        int x = a[i], y = a[n-1-i], Tans = 2;
        FOR (j, 4) {
            FOR (k, 4) {
                int cur = (x != temp[j]) + (y != temp[k]);
                vector< int > dum = {temp[j], temp[k], b[i], b[n-1-i]};
                sort(dum.begin(), dum.end());
                if (dum[0] == dum[1] && dum[2] == dum[3]) {
                    Tans = min(Tans, cur);
                } 
            }
        }
        ans += Tans;
    }
    if ((n & 1) && a[n/2] != b[n/2]) {
        ans++;
    }
    cout << ans << '\n';
}