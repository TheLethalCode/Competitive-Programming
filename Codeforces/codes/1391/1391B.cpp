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
        int n, m, cnt = 0;
        cin >> n >> m;
        char r;
        FOR(i, n){
            FOR(j, m){
                cin >> r;
                if(i == n-1 && j==m-1){
                    continue;
                }
                cnt += (i==n-1?r=='D':j==m-1?r=='R':0);
            }
        }
        cout << cnt << '\n';
    }
}