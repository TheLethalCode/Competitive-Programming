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
#define MAXC 2000005
// %

int n, m, i, j, t, q, ok, cnt, cur, V[MAXC];
lli k, r, x, y, ans;
string s, c;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector< int > cnt(MAXC+100, 0);
    vector< pair< lli, lli > > pref(MAXC+100);
    cnt[1] = 1;
    cnt[2] = 2;
    lli z = 1, sum = 1;
    pref[1] = {1, 1};
    for(cur = 2, i=2; cur < MAXC;i++){
        FOR(j, cnt[i]){
            z += i;
            sum = (sum + 1LL*i*cur*cur)  % mod;
            cnt[cur] = i;
            pref[cur++] = {z, sum};
        }
    }
    pref.resize(cur);
    auto calc = [&](lli r){
        int pos = lower_bound(pref.begin(), pref.end(), make_pair(r+1, (lli)(-1))) - pref.begin() - 1;
        lli rem = r - pref[pos].fi;
        return (pref[pos].se + rem*(pos+1)*(pos+1)) % mod;
    };
    cin >> t;
    while(t--){
        cin >> x >> y;
        cout << (calc(y) - calc(x-1) + mod) % mod << '\n';
    }
}