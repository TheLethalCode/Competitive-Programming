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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(q=1;q<=t;q++){
        cin >> n >> s;
        vector< int > cnt(2);
        FORR(x, s){
            cnt[x-'A']++;
        }
        cout << "Case #" << q << ": " << (abs(cnt[0]-cnt[1])==1?'Y':'N') << '\n';
    }
}