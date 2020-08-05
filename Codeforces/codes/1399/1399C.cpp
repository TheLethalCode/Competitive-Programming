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
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        vector< int > v(n), mark(101, 0);
        FOR(i, n){
            cin >> v[i];
            mark[v[i]]++;
        }
        set< int > S;
        FOR(i, n){
            FOR(j, i){
                S.insert(v[i] + v[j]);
            }
        }
        FORR(sum, S){
            vector< int > temp = mark;
            int te = 0;
            FOR(i, sum){
                int x = min(temp[i+1], temp[sum - i -1]);
                if(i+1 == sum - i - 1){
                    x = temp[i+1] >> 1;
                }
                temp[sum - i - 1] -= x;
                temp[i+1] -= x;
                te += x;
            }
            ans = max(ans, te);
        }
        cout << ans << '\n';
    }
}