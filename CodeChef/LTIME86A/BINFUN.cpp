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

int n, m, i, j, t, q, ok, cnt, V[MAXC];
lli k, r, x, y, z, ans;
string s, c;

lli func(int a, int b){
    i = 32 - __builtin_clz(a);
    j = 32 - __builtin_clz(b);
    lli AB = ((lli)a<<j) + b;
    lli BA = ((lli)b<<i) + a;
    return abs(AB - BA);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector< int > bS(31, 1<<30), bB(31, -1);
        FOR(i, n){
            cin >> V[i];
            int b = 32 - __builtin_clz(V[i]);
            bS[b] = min(bS[b], V[i]);
            bB[b] = max(bB[b], V[i]);
        }
        ans = 0;
        FOR(i, 31){
            FOR(j, 31){
                if(bS[i]!=1<<30 && bB[j]!=-1){
                    ans = max(ans, func(bS[i], bB[j]));
                }
            }
        }
        cout << ans << '\n';
    }
}