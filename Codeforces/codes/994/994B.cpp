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
    int n, k;
    cin >> n >> k;
    vector < pair<pair<int,int>,int> > V(n);
    FOR (i, n) {
        cin >> V[i].fi.fi;
    }
    FOR (i, n) {
        cin >> V[i].fi.se;
        V[i].se = i;
    }
    sort(V.begin(), V.end());
    multiset < int > S;
    lli ans = 0;
    vector< lli > pri(n);
    FOR (i, n) {
        ans += V[i].fi.se;
        pri[V[i].se] = ans;
        S.insert(V[i].fi.se);
        if (S.size() > k) {
            ans -= *S.begin();
            S.erase(S.begin());
        }
    }
    FOR (i, n) {
        cout << pri[i] << ' ';
    }
    cout << '\n';
}